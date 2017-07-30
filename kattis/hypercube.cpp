#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const long long MAXN = 64;

long long n;
char a[MAXN];
char b[MAXN];

long long index(char* s, long long n, long long start) {
    long long len = n - start;
    if (len == 1LL) {
        return s[start] - '0';
    } else if (s[start] == '0') {
        return index(s, n, start + 1LL);
    } else {
        return (1LL << len) - 1LL - index(s, n, start + 1LL);
    }
}

int main() {
    scanf("%lld %s %s", &n, a, b);

    long long x = index(a, n, 0);
    long long y = index(b, n, 0);

    printf("%lld\n", y - x - 1LL);

    return 0;
}
