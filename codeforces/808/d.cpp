#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <complex>

using namespace std;

const long long MAXN = 100005;
long long n;
long long a[MAXN];
long long p[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%lld", &n);
    p[0] = 0LL;

    for (long long i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        p[i] = p[i - 1] + a[i];
    }

    map<long long, long long> a1;
    map<long long, long long> a2;
    for (long long i = 1; i <= n; ++i) {
        ++a2[a[i]];
    }

    long long sum = p[n];
    bool solved = false;
    // last index of first partition
    for (long long i = 0; !solved and i <= n; ++i) {
        if (i > 0) {
            ++a1[a[i]];
            --a2[a[i]];
        }

        long long left_sum = p[i];
        long long right_sum = sum - left_sum;

        if (left_sum > right_sum) {
            long long diff = left_sum - right_sum;
            if (diff % 2 == 1) continue;

            diff /= 2;

            if (a1[diff] > 0) {
                solved = true;
            }
        } else if (left_sum == right_sum) {
            solved = true;
        } else {
            long long diff = right_sum - left_sum;
            if (diff % 2 == 1) continue;

            diff /= 2;

            if (a2[diff] > 0) {
                solved = true;
            }
        }
    }

    printf("%s\n", solved ? "YES" : "NO");
    return 0;
}
