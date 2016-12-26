#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main() {
    long long r, c;
    long long k;
    cin >> r >> c >> k;

    long long lo = 0LL;
    long long hi = 1000000070LL;
    while (lo + 1LL < hi) {
        long long mid = (lo + hi) / 2LL;
        if (mid * mid >= k) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    long long side1 = min(min(r, c), hi);
    long long side2 = k / side1;
    if (k % side1 != 0) {
        ++side2;
    }

    cout << (2LL * (side1 + side2)) << '\n';

    return 0;
}
