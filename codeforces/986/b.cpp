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

constexpr int MAXN = 1000006;
int n;
int a[MAXN];
bool vis[MAXN];

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = true;
    dfs(a[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &a[i]);
        --a[i];
    }

    int comps = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ++comps;
            dfs(i);
        }
    }

    printf("%s\n", (comps & 1) ? "Um_nik" : "Petr");

    return 0;
}
