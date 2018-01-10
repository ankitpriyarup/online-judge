#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100005;
int n;
int perm[MAXN];
bool visit[MAXN];
int comp;

void dfs(int i) {
    ++comp;
    visit[i] = true;
    if (!visit[perm[i]])
        dfs(perm[i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", perm + i);
    }

    vector<int> sizes;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            comp = 0;
            dfs(i);
            sizes.push_back(comp);
        }
    }

    sort(begin(sizes), end(sizes));
    if (sizes.size() >= 2) {
        int x = sizes.back();
        sizes.pop_back();
        sizes[sizes.size() - 1] += x;
    }

    ll ans = n;
    for (int x : sizes) {
        ans += 1LL * x * (x - 1);
    }

    printf("%lld\n", ans);
    
    return 0;
}
