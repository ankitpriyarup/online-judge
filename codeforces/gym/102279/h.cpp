#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 9;
int n;
int a[MAXN], b[MAXN];
int vis[MAXN];
vector<pair<int, int>> stk;

void rec(int x) {
    stk.emplace_back(x, vis[x]);
    bool all_used = true;
    int goal = vis[x] ? a[x] : b[x];
    for (int i = 0; i < n; ++i) {
        if (vis[i] == -1) {
            all_used = false;

            if (a[i] == goal) {
                vis[i] = 0;
                rec(i);
                vis[i] = -1;
            }

            if (b[i] == goal) {
                vis[i] = 1;
                rec(i);
                vis[i] = -1;
            }
        }
    }

    if (all_used) {
        while (!stk.empty()) {
            cout << (stk.back().first + 1) << ' ' << static_cast<char>('b' - stk.back().second) << '\n';
            stk.pop_back();
        }

        exit(0);
    }

    stk.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    memset(vis, -1, sizeof(vis));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 2; ++k) {
            vis[i] = k;
            rec(i);
            vis[i] = -1;
        }
    }

    return 0;
}
