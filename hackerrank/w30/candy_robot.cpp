#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, t;
int a[102];

int main() {
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= t; ++i) {
        scanf("%d", a + i);
    }

    int bowl = n;
    long long refill = 0;
    for (int i = 1; i < t; ++i) {
        bowl -= a[i];
        if (bowl < 5) {
            refill += n - bowl;
            bowl = n;
        }
    }

    printf("%lld\n", refill);
    return 0;
}
