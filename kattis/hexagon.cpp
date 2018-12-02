#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

namespace mcmf {
  const int MAXV = 500;
  const int MAXE = 500 * 500;
  const long long oo = 1e18;

  int V, E;
  int last[MAXV], curr[MAXV], bio[MAXV]; long long pi[MAXV];
  int next[MAXE], adj[MAXE]; long long cap[MAXE], cost[MAXE];

  void init(int n) {
    V = n;
    E = 0;
    for (int i = 0; i < V; ++i) {
        last[i] = -1;
    }
  }

  void edge(int x, int y, long long c, long long w) {
    adj[E] = y; cap[E] = c; cost[E] = +w; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = 0; cost[E] = -w; next[E] = last[y]; last[y] = E++;
  }

  long long push(int x, int sink, long long flow) {
    if (x == sink) return flow;
    if (bio[x]) return 0;
    bio[x] = true;

    for (int &e = curr[x]; e != -1; e = next[e]) {
      int y = adj[e];

      if (cap[e] && pi[x] == pi[y] + cost[e])
        if (long long f = push(y, sink, min(flow, cap[e])))
          return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }

  pair<long long, long long> run(int src, int sink) {
    long long total = 0;
    long long flow = 0;

    for (int i = 0; i < V; ++i) {
        pi[i] = oo;
    }
    pi[sink] = 0;

    for (;;) {
      bool done = true;
      for (int x = 0; x < V; ++x)
          for (int e = last[x]; e != -1; e = next[e])
            if (cap[e] && pi[x] > pi[adj[e]] + cost[e])
              pi[x] = pi[adj[e]] + cost[e], done = false;
      if (done) break;
    }

    for (;;) {
      for (int i = 0; i < V; ++i)
          bio[i] = false;
      for (int i = 0; i < V; ++i)
          curr[i] = last[i];

      while (long long f = push(src, sink, oo)) {
        total += pi[src] * f;
        flow += f;
        for (int i = 0; i < V; ++i) bio[i] = false;
      }

      long long inc = oo;
      for (int x = 0; x < V; ++x) if (bio[x]) {
        for (int e = last[x]; e != -1; e = next[e]) {
          int y = adj[e];
          if (cap[e] && !bio[y]) inc = min(inc, pi[y] + cost[e] - pi[x]);
        }
      }
      if (inc == oo) break;

      for (int i = 0; i < V; ++i) if (bio[i]) pi[i] += inc;
    }
    return make_pair(total, flow);
  }
}

pair<vector<pii>, vector<vector<int>>> make_hex(int s) {
    vector<pii> id_to_pos = {{-1, -1}};
    vector<vector<int>> grid(s, vector<int>(s, 0));
    int id = 1;
    int row_start = 0;
    int row_len = (s + 1) >> 1;
    int step = 1;
    int shift = 0;
    for (int i = 0; i < s; ++i) {
        for (int j = row_start; j < row_start + row_len; ++j) {
            grid[i][j] = id++;
            id_to_pos.emplace_back(i, j);
        }

        if (row_len == s) {
            step = -1;
            shift = 1;
        }

        row_len += step;
        row_start += shift;
    }

    return {id_to_pos, grid};
}

/*
 * 123
 * 4567
 * 89012
 *  3456
 *   789
 */

int dx[] = {0, 1, 0, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, -1};

string buf;
void solve() {
    getline(cin, buf);
    istringstream iss(buf);

    vector<int> starts, values;
    int v;
    while (iss >> v) {
        starts.push_back(v);
    }

    getline(cin, buf);
    istringstream iss2(buf);
    while (iss2 >> v) {
        values.push_back(v);
    }

    assert(starts.size() == values.size());

    int s = starts.size();

    // apsp on a hexagon T_T
    vector<pii> id_to_pos; 
    vector<vector<int>> grid;
    tie(id_to_pos, grid) = make_hex(s);

    /*
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << '\n';
    }
    */

    int tot_cells = id_to_pos.size();
    int INF = s * s * s * s;
    vector<vector<int>> dist(s, vector<int>(tot_cells, INF));
    --tot_cells;

    for (int i = 0; i < s; ++i) {
        dist[i][starts[i]] = 0;
        queue<pii> q;
        q.push(id_to_pos[starts[i]]);

        int x, y;
        while (!q.empty()) {
            tie(x, y) = q.front();
            q.pop();

            for (int d = 0; d < 6; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (0 <= nx and nx < s and 0 <= ny and ny < s and grid[nx][ny] != 0) {
                    if (dist[i][grid[x][y]] + 1 < dist[i][grid[nx][ny]]) {
                        dist[i][grid[nx][ny]] = dist[i][grid[x][y]] + 1;
                        q.emplace(nx, ny);
                    }
                }
            }
        }
    }

    // now wire up the MCMF 3 times and go!
    // source to chips
    // chips to pos
    // pos to sink
    // all capacities are 1
    // src / sink weights are 0, other weights are distances
    int half = s >> 1;
    vector<vector<int>> diagonals(3);
    for (int i = 0; i < s; ++i) {
        diagonals[0].push_back(grid[i][i]);
        diagonals[1].push_back(grid[i][half]);
        diagonals[2].push_back(grid[half][i]);
    }

    ll ans = 1LL * s * s * s * s * s;
    for (int k = 0; k < 3; ++k) {
        // [0, s) tokens
        // [s, 2s) dests
        int src = 2 * s;
        int sink = 2 * s + 1;
        mcmf::init(sink + 1);
        for (int i = 0; i < s; ++i) {
            mcmf::edge(src, i, 1, 0);
            mcmf::edge(s + i, sink, 1, 0);
            for (int j = 0; j < s; ++j) {
                int distance = dist[i][diagonals[k][j]];
                mcmf::edge(i, s + j, 1, values[i] * distance);
                // cout << "Edge " << starts[i] << " -> " << diagonals[k][j] << " cap " << 1 << " cost " << (values[i] * distance) << '\n';
            }
        }

        ans = min(ans, mcmf::run(src, sink).first);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    getline(cin, buf);

    int tc = 1;
    while (T-- > 0) {
        cout << "Case #" << tc++ << ": ";
        solve();
    }
    
    return 0;
}
