#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 500005;
const int MOD = 1000000007;
char str[MAXN];

inline int sum(const int& a, const int& b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

inline int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}

const int inv2 = (MOD + 1) / 2;

int main() {
    scanf("%s", str);
    int n = strlen(str);

    int qs = 0;
    int total_strings = 1;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '?') {
            ++qs;
            total_strings <<= 1;
            total_strings %= MOD;
        }
    }

    int ones = 0;
    int q = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '1')
            ++ones;
        else if (str[i] == '0') {
            ans = sum(ans, prod(ones, total_strings));
            ans = sum(ans, prod(inv2, prod(q, total_strings)));
        } else {
            ans = sum(ans, prod(inv2, prod(ones, total_strings)));
            ans = sum(ans, prod(inv2, prod(inv2, prod(q, total_strings))));

            ++q;
        }
    }

    printf("%d\n", ans);

    return 0;
}
