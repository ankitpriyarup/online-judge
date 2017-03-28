#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 1000006;
const int MOD = 1000000007;

int n, m;
int fact[MAXN];

inline int prod(int a, int b) {
    return (1LL * a * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &m);

    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        fact[i] = prod(i, fact[i - 1]);

    vector<vector<int> > types(m, vector<int>());
    for (int i = 0; i < m; ++i)
        types[i].clear();

    int g;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &g);

        int type;
        for (int j = 0; j < g; ++j) {
            scanf("%d", &type);
            types[type - 1].push_back(i);
        }
    }

    sort(types.begin(), types.end());

    int ans = 1;
    int comp = 1;
    vector<int> last = types[0];

    for (int i = 1; i < m; ++i) {
        if (types[i] == types[i - 1]) {
            ++comp;
        } else {
            ans = prod(ans, fact[comp]);
            comp = 1;
            last = types[i];
        }
    }

    ans = prod(ans, fact[comp]);
    printf("%d\n", ans);

    return 0;
}
