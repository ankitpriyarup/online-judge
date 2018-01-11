#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int RANGE = 10;

int main() {
    int T;
    scanf("%d", &T);

    long long a, b, ab;
    while (T-- > 0) {
        scanf("%lld %lld", &a, &b);
        ab = a * b;
        long long c = pow(ab, 1.0 / 3.0);
        bool valid = false;

        for (int delta = -RANGE; delta < RANGE; ++delta) {
            long long x = c + delta;
            if (x * x * x == ab and a % x == 0 and b % x == 0) {
                valid = true;
                break;
            }
        }

        printf("%s\n", valid ? "Yes" : "No");
    }

    return 0;
}
