#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, m;
vector<int> graph[100005];
int color[100005];
bool valid = true;

void dfs(int n, int p, int c) {
  //cout << "dfs(" << n << ", " << p << ", " << c << ");\n";
  if (!valid) return;

  color[n] = c;
  for (int child : graph[n]) {
    if (child != p) {
      if (color[child] == 0)
        dfs(child, n, 3 - c);

      if (color[child] == c) {
        valid = false;
        break;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  
  int u, v;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  memset(color, 0, sizeof(color));
  for (int i = 1; i <= n; ++i) {
    if (color[i] == 0)
      dfs(i, 0, 1);
  }

  if (!valid) {
    cout << -1 << '\n';
  } else {
    vector<int> a;
    vector<int> b;
    for (int i = 1; i <= n; ++i) {
      if (color[i] == 1) {
        a.push_back(i);
      } else {
        b.push_back(i);
      }
    }

    cout << a.size() << '\n';
    cout << a[0];
    for (int i = 1; i < a.size(); ++i) {
      cout << ' ' << a[i];
    }
    cout << '\n';

    cout << b.size() << '\n';
    cout << b[0];
    for (int i = 1; i < b.size(); ++i) {
      cout << ' ' << b[i];
    }
    cout << '\n';
  }

  return 0;
}
