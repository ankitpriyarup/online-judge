#include <cstdio>
#include <vector>

using namespace std;

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    scanf("%d", &n);

    vector<int> vals;
    int x;
    scanf("%d", &x);
    vals.push_back(x);

    int extra = 0;
    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        if (gcd(vals.back(), x) > 1) {
            ++extra;
            vals.push_back(1);
        }

        vals.push_back(x);
    }

    printf("%d\n", extra);
    for (int x : vals) 
        printf("%d ", x);
    printf("\n");

    return 0;
}
