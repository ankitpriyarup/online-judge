#include <cstdio>

using namespace std;

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);

    long long winners = n / 2LL;
    winners -= winners % (k + 1);

    long long diploma = winners / (k + 1LL);

    printf("%lld %lld %lld\n", diploma, winners - diploma, n - winners);
    return 0;
}
