#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    long long score = 0;
    long long bump = 1;

    for (int i = 1; i <= T; ++i) {
        score += bump;
        if (i % 2 == 1) {
            bump++;
        }
    }

    printf("%lld\n", score);
    return 0;
}
