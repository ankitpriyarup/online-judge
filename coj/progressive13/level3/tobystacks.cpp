#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1000006;
// id -> tree node
int pos[MAXN];

// tree node -> parent node
int par[MAXN];
// tree node -> depth
int depth[MAXN];
// tree node -> value
int val[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    pos[0] = 0;
    val[0] = -1;

    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int id, op;
        cin >> id >> op;
        id = pos[id];
        if (op == 0) {
            int v;
            cin >> v;

            pos[i] = i;
            par[i] = id;
            val[i] = v;
            depth[i] = depth[id] + 1;

            cout << depth[i] << '\n';
        } else {
            pos[i] = par[id];

            cout << val[id] << '\n';
        }
    }
    
    return 0;
}
