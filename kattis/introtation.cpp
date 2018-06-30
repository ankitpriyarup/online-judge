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

int c2[11];

constexpr int MAXV = 1e6 + 6;
vector<int> rot[MAXV];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i < 10; ++i) {
        c2[i] = i * (i - 1) / 2;
        rot[i].push_back(i);
    }

    int scale = 10;
    for (int i = 10; i < MAXV; ++i) {
        if (i == 10 * scale)
            scale *= 10;

        int x = i;
        do {
            int last_dig = x % 10;
            x = (x / 10) + scale * last_dig;
            if (x >= scale) {
                // printf("%d -> %d\n", i, x);
                rot[i].push_back(x);
            }
        } while (x != i);
    }

    int T, a, b;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf(" %d %d", &a, &b);
        bitset<MAXV> bs;
        int ans = 0;
        for (int i = a; i <= b; ++i) {
            if (bs[i]) continue;
            int ct = 0;
            if (rot[i].size() < 2) continue;
            for (int x : rot[i]) {
                if (a <= x and x <= b) {
                    bs[x] = true;
                    ++ct;
                }
            }

            ans += c2[ct];
        }

        printf("%d\n", ans);
    }

    return 0;
}
