#include <iostream>

using namespace std;

int K, N;
long long R[10004];

int main() {
    cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        cin >> R[i];
        R[i] *= R[i];
    }

    /*
    cout << "Radii: ";
    for (int i = 0; i < K; ++i) {
        cout << R[i] << ' ';
    }
    cout << '\n';
    */

    long long x, y;
    long long ans = 0LL;

    while (N-- > 0) {
        cin >> x >> y;
        long long dist = x * x + y * y;
        // binary search over R to find the smallest R[i] >= dist 
        if (dist > R[0]) continue;
        if (dist <= R[K - 1]) {
            ans += K;
            continue;
        }

        int lo = 0;
        int hi = K - 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (dist <= R[mid]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }

        //cout << x << ", " << y << " " << dist << " " << (lo + 1) << '\n';
        ans += lo + 1;
    }

    cout << ans << '\n';

    return 0;
}
