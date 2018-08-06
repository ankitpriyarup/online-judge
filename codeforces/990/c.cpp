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

constexpr int MAXN = 300005;
int n;
char s[MAXN];
char t[MAXN];
int freq[2 * MAXN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        scanf(" %s", s);
        int m = strlen(s);
        int score = 0;
        int ptr = 0;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '(') {
                t[ptr++] = s[j];
            } else {
                if (ptr and t[ptr - 1] == '(') {
                    --ptr;
                } else {
                    t[ptr++] = s[j];
                }
            }
        }

        if (ptr == 0) {
            ans += 2LL * freq[MAXN] + 1;
            ++freq[MAXN];
        } else if (t[0] == ')' and t[ptr - 1] == ')') {
            ans += freq[ptr + MAXN];
            ++freq[-ptr + MAXN];
        } else if (t[0] == '(' and t[ptr - 1] == '(') {
            ans += freq[-ptr + MAXN];
            ++freq[ptr + MAXN];
        }
    }

    printf("%lld\n", ans);
    
    return 0;
}
