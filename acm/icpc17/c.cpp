#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

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
const int MAXN = 102;
int n, m;
int a[MAXN][MAXN];
int max_row[MAXN];
int max_col[MAXN];

void read() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int max_cur = 0;
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            max_cur = max(max_cur, a[i][j]);
        }

        max_row[i] = max_cur;
    }

    for (int j = 0; j < m; ++j) {
        int max_cur = 0;
        for (int i = 0; i < n; ++i) {
            max_cur = max(max_cur, a[i][j]);
        }

        max_col[j] = max_cur;
    }
}

int main() {
    read();

    int source = n + m;
    int sink = n + m + 1;

    mcmf::init(sink + 1);

    for (int i = 0; i < n; ++i) {
        mcmf::edge(source, i, 1, 0);
    }

    for (int j = 0; j < m; ++j) {
        mcmf::edge(n + j, sink, 1, 0);
    }

    long long ans = 0LL;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ans += max(0, a[i][j] - 1);
            if (max_row[i] != 0 and max_row[i] == max_col[j] and a[i][j] != 0) {
                mcmf::edge(i, n + j, 1, -1 * (max_row[i] - 1));
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ans -= max(0, max_row[i] - 1);
    }

    for (int j = 0; j < m; ++j) {
        ans -= max(0, max_col[j] - 1);
    }

    ans -= mcmf::run(source, sink).first;

    printf("%lld\n", ans);

    return 0;
}
