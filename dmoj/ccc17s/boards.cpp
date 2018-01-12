#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXL = 2002;
long long freq[MAXL];

int main() {
    int n;
    scanf("%d", &n);

    int l;
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l);
        ++freq[l];
    }

    long long ans_length = 0;
    long long ans_ways = 0;
    for (int total = 2; total <= 2 * MAXL; total++) {
        long long length = 0LL;
        for (int a = 1; a <= total / 2; ++a) {
            int b = total - a;
            if (b < 0 or b >= MAXL) continue;
            if (a == b) {
                length += freq[a] / 2;
            } else {
                length += min(freq[a], freq[b]);
            }
        }

        // priintntf("%d %lld\n", total, length);

        if (length > ans_length) {
            ans_length = length;
            ans_ways = 0;
        }

        if (length == ans_length) {
            ++ans_ways;
        }
    }

    printf("%lld %lld\n", ans_length, ans_ways);
    return 0;
}
