#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T, K, a[12];
    cin >> T;
    while (T-- > 0) {
        cin >> K;
        for (int i = 0; i < 12; ++i) {
            cin >> a[i];
        }

        int ans = 0;
        for (int start = 1; start < 11; start++) {
            for (int end = start; end < 11; end++) {
                long long m = 1LL << 60;
                for (int i = start; i <= end; ++i) {
                    m = min(m, (long long) a[i]);
                }
                if (m > a[start - 1] && m > a[end + 1]) {
                    //cout << "From " << start << " to " << end << '\n';
                    ans += 1;
                }
            }
        }

        cout << K << " " << ans << '\n';
    }
    return 0;
}
