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

constexpr int MAXN = 20004;
constexpr int MAXA = 11;
int n;
char s[MAXN];
bool hit[1 << MAXA];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%s", s);
        n = strlen(s);
        bool output = false;

        for (int a = MAXA; !output and a >= 0; --a) {
            int sz = a * (1 << a);
            if (sz > n) continue;
            for (int start = 0; !output and start + sz <= n; ++start) {
                memset(hit, 0, sizeof(hit));
                bool works = true;

                for (int ctr = 0; !output and ctr < (1 << a); ++ctr) {
                    int pos = start + ctr * a;
                    int mask = 0;
                    for (int i = 0; i < a; ++i) {
                        if (s[pos + i] == 'T') {
                            mask |= (1 << i);
                        }
                    }

                    if (hit[mask]) {
                        works = false;
                        break;
                    }

                    hit[mask] = true;
                }

                if (works) {
                    printf("%d %d\n", a, start);
                    output = true;
                }
            }
        }
    }
    
    return 0;
}
