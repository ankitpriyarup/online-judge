#include <cstdio>
#include <algorithm>

using namespace std;

int n, p;

long double f(int white) {
    long double ans = 1.0L * p * white / (n + 1);
    for (int k = 2; k <= white; ++k) {
        ans *= (n - p + k);
        ans /= (n + k);
    }

    return ans;
}

int main() {
    scanf("%d %d", &n, &p);

    int ans = n / (p - 1);
    long double d1 = f(ans);
    long double d2 = f(ans + 1);

    printf("%.12Lf\n", max(d1, d2));

    return 0;
}
