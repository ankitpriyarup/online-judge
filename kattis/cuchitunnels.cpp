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

constexpr int MAXN = 1003;
int n;
int deg[MAXN];
vector<int> tree[MAXN];
int next_node = 2;
bool valid = true;

void dfs(int node) {
    if (!valid) return;
    while (deg[node]) {
        --deg[node];
        --deg[next_node];
        if (next_node > n or deg[next_node] < 0) {
            valid = false;
            break;
        }

        // printf("Edge from %d to %d\n", node, next_node);
        tree[node].push_back(next_node);
        ++next_node;
        dfs(next_node - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int sum = 0;
    valid = true;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", deg + i);
        sum += deg[i];
        if (deg[i] == 0) 
            valid = false;
    }

    // printf("sum: %d\n", sum);
    if (!valid or sum != 2 * (n - 1)) {
        printf("NO\n");
        return 0;
    }

    dfs(1);
    for (int i = 1; i <= n; ++i) {
        if (deg[i] != 0) {
            valid = false;
        }
    }

    printf("%s\n", valid ? "YES" : "NO");

    return 0;
}
