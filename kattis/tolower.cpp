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

constexpr int MAXN = 50004;
int n;
char s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int ans = 0;
    int p, t;
    scanf("%d %d", &p, &t);
    while (p-- > 0) {
        bool pass = true;
        for (int i = 0; i < t; ++i) {
            scanf("%s", s);
            int n = strlen(s);
            for (int i = 1; i < n; ++i) {
                pass &= 'a' <= s[i] and s[i] <= 'z';
            }
        }

        if (pass)
            ++ans;
    }

    printf("%d\n", ans);

    return 0;
}
