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
int n, m;
vector<int> starts[MAXN], finishes[MAXN];
bool is_active[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d", &a, &b);
        starts[a].push_back(i);
        finishes[b].push_back(i);
    }

    vector<int> active;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int v : finishes[i]) {
            if (is_active[v]) {
                ++ans;
                for (int x : active) {
                    is_active[x] = false;
                }
                active.clear();
                break;
            }
        }

        for (int v : starts[i]) {
            active.push_back(v);
            is_active[v] = true;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
