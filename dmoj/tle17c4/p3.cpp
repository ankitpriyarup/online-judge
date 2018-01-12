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

constexpr int MAXN = 300005;
int n, m, d;
vector<int> tree[MAXN];
int par[MAXN];
int score[MAXN];
bool have[MAXN];

void prop(int x) {
    if (x == 0 or score[x] != tree[x].size()) {
        return;
    }
    if (!have[x]) {
        have[x] = true;
        ++score[par[x]];
        prop(par[x]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &m, &d);
    int target, k, x;
    par[0] = 1;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &target, &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &x);
            tree[target].push_back(x);
            par[x] = target;
        }
    }

    for (int day = 1; day <= d; ++day) {
        scanf("%d", &x);
        score[x] = tree[x].size();
        prop(x);

        if (have[1]) {
            printf("%d\n", day);
            return 0;
        }
    }

    printf("%d\n", -1);
    
    return 0;
}
