#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long ans = k;
    for (int i = 0; i < n - 1; ++i) {
        ans *= (k - 1);
    }

    cout << ans << '\n';
}
