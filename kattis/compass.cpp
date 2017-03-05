#include <cstdio>

using namespace std;

int solve(int n, int m) {
    int pos, neg;
    if (n == m) {
        return 0;
    } else if (n < m) {
        pos = m - n;
        neg = n + 360 - m;
    } else {
        pos = m + 360 - n;
        neg = n - m;
    }

    if (pos <= neg) {
        return pos;
    } else {
        return -neg;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d\n", solve(n, m));
    return 0;
}

