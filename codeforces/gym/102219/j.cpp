#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<vi> graph(5);
    vi in_deg(5, 0);
    for (int i = 0; i < 5; ++i) {
        string s;
        cin >> s;
        int x = s[0] - 'A';
        int y = s[2] - 'A';
        if (s[1] == '>') {
            graph[y].push_back(x);
            ++in_deg[x];
        } else {
            graph[x].push_back(y);
            ++in_deg[y];
        }
    }

    queue<int> q;
    string res;
    for (int i = 0; i < 5; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u + 'A');
        for (int v : graph[u]) {
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }

    if (res.size() == 5) {
        cout << res << '\n';
    } else {
        cout << "impossible\n";
    }
    
    return 0;
}
