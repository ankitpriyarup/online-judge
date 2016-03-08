#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int T, N, x, y;
    int a[100005];

    cin >> T;

    while (T-- > 0) {
        cin >> N;
        cin >> x;
        for (int i = 1; i < N; ++i) {
            cin >> y;
            x = gcd(x, y);
        }

        cout << (1LL * x * N) << '\n';
    }

    return 0;
}
