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
int n, m;
char s[MAXN], t[MAXN];
ll freq_s[30], freq_t[30];

bool works(ll f) {
    ll needed = 0;
    for (int i = 0; i < 26; ++i) {
        needed += max(0LL, 1LL * f * freq_t[i] - freq_s[i]);
    }

    return needed <= 1LL * freq_s[26];
}

void build(ll f) {
    // printf("f: %d\n", f);
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?')
            continue;

        for (int j = 0; j < 26; ++j) {
            if (freq_s[j] < 1LL * f * freq_t[j]) {
                ++freq_s[j];
                s[i] = (j + 'a');
                break;
            }
        }

        if (s[i] == '?')
            s[i] = 'a';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    scanf("%s", t);

    n = strlen(s);
    m = strlen(t);

    memset(freq_s, 0, sizeof(freq_s));
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?')
            ++freq_s[26];
        else
            ++freq_s[s[i] - 'a'];
    }

    for (int i = 0; i < m; ++i) {
        ++freq_t[t[i] - 'a'];
    }

    ll lo = 0;
    ll hi = 1e12;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2LL;
        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    build(lo);

    printf("%s\n", s);

    return 0;
}
