#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using ll = long long;
using namespace std;

namespace dinic {
  const int MAXV = 1000100;
  const int MAXE = 1000100;
  const ll oo = 1e18;

  int V, E;
  int last[MAXV], dist[MAXV], curr[MAXV];
  int next[MAXE], adj[MAXE]; ll cap[MAXE];

  void init(int n) {
    V = n;
    E = 0;
    memset(last, -1, sizeof(last));
  }

  void edge(int x, int y, ll c1 = 1, ll c2 = 1) {
    adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
  }

  ll push(int x, int sink, ll flow) {
    if (x == sink) return flow;

    for (int &e = curr[x]; e != -1; e = next[e]) {
      int y = adj[e];

      if (cap[e] && dist[x] + 1 == dist[y])
        if (ll f = push(y, sink, min(flow, cap[e])))
          return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }

  ll run(int src, int sink) {
    ll ret = 0;
    for (;;) {
      for (int i = 0; i < V; ++i) {
          curr[i] = last[i];
      }
      
      memset(dist, -1, sizeof(dist));

      queue<int> Q;
      Q.push(src), dist[src] = 0;

      while (!Q.empty()) {
        int x = Q.front(); Q.pop();

        for (int e = last[x]; e != -1; e = next[e]) {
          int y = adj[e];
          if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
        }
      }
      if (dist[sink] == -1) break;

      while (ll f = push(src, sink, oo)) ret += f;
    }
    return ret;
  }
}

int n, m;
int main() {
    scanf("%d %d", &n, &m);
    int src = 2 * n + 2;
    int sink = 2 * n + 3;
    dinic::init(sink + 1);
    for (int i = 0; i <= n; ++i) {
        dinic::edge(src, 2 * i);
        dinic::edge(2 * i + 1, sink);
    }
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        dinic::edge(2 * u, 2 * v + 1);
    }
    int fill = dinic::run(src, sink);
    if (fill == n) { 
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
