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

int n;
int OFF = 10005;
int a[11111];
bool vis[22222];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (scanf(" %d", &n) == 1) {
        if (!n) break;

        scanf(": %d", a);
        for (int i = 1; i < n; ++i) {
            scanf(" %d", a + i);
        }

        bool anti = true;
        for (int i = 1; anti and i + 1 < n; ++i) {
            memset(vis, 0, sizeof(vis));
            for (int j = i + 1; j < n; ++j) {
                int d = a[j] - a[i];
                vis[d + OFF] = true;
            }

            for (int j = i - 1; j >= 0; --j) {
                int d = a[i] - a[j];
                if (vis[d + OFF]) {
                    anti = false;
                    break;
                }
            }
        }

        printf("%s\n", anti ? "yes" : "no");
    }
    
    return 0;
}
