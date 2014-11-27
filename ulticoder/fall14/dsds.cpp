#include <iostream>

using namespace std;

int N;
long long D;

long long bin_search(long long square) {
    long long lo = 0;
    long long hi = 1e8;

    long long mid = (lo + hi) / 2;
    while (mid * mid != square) {
        if (mid * mid < square) {
            lo = mid;
        } else {
            hi = mid;
        }
        mid = (lo + hi) / 2;
    }

    return mid;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> D;
        cout << "The DSDS roots of " << D;
        long long ans = bin_search(D / 2);
        cout << " are " << ans << " and " << (ans + 1) << endl;
    }
    return 0;
}
