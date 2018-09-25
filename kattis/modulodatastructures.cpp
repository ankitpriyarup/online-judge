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
constexpr int SQRTN = 500;
int n, q;
int v[MAXN];
int tab[SQRTN][SQRTN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &q);
    int op;
    int a, b, c;
    while (q-- > 0) {
        scanf(" %d", &op);
        if (op == 1) {
            scanf(" %d %d %d", &a, &b, &c);
            if (b < SQRTN) {
                tab[b][a] += c;
            } else {
                for (int i = a; i <= n; i += b) {
                    v[i] += c;
                }
            }
        } else {
            scanf(" %d", &a);
            int ans = v[a];
            for (int b = 1; b < SQRTN; ++b) {
                ans += tab[b][a % b];
            }
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
