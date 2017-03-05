#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 404;
int n;
long long prices[MAXN];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%lld", prices + i);
    }

    long long money = 100;
    prices[0] = 1e9;
    for (int i = 1; i <= n; ++i) {
        if (prices[i] > prices[i - 1]) {
            long long shares = min(money / prices[i - 1], 100000LL);
            money += shares * (prices[i] - prices[i - 1]);
        }
    }

    printf("%lld\n", money);

    return 0;
}
