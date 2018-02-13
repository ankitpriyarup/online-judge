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

constexpr int MAXN = 200005;
constexpr int MOD = 1e9 + 7;
int n;
vector<int> tree[MAXN];
int fact[MAXN];

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

int solve(int u) {
    int child_prod = 1;
    for (int v : tree[u]) {
        child_prod = prod(child_prod, solve(v));
    }

    // (number of children + 1) * product of children solves
    return prod(tree[u].size() + 1, prod(fact[tree[u].size()], child_prod));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        fact[i] = prod(i, fact[i - 1]);

    scanf("%d", &n);
    int par;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &par);
        tree[par].push_back(i);
    }

    printf("%d\n", solve(0));

    return 0;
}
