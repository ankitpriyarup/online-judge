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

int n, x;
bool adj[55][55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &x);
    for (int i = 1; i <= n; ++i) {
        int d, j;
        scanf(" %d", &d);
        while (d-- > 0) {
            scanf(" %d", &j);
            adj[i][j] = 1;
            adj[j][i] = 1;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (i == x or adj[i][x]) continue;
        bool fof = false;
        for (int k = 1; k <= n; ++k) {
            fof |= (i != k and k != x and adj[i][k] and adj[k][x]);
        }

        if (fof)
            ans.push_back(i);
    }
    printf("%lu\n", ans.size());
    for (int x : ans)
        printf("%d ", x);

    return 0;
}
