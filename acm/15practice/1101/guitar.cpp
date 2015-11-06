#include <iostream>

using namespace std;

int main() {
    int T, K, a[1000006];
    cin >> T;

    for (int cnum = 1; cnum <= T; ++cnum) {
        cin >> K;
        for (int i = 0; i < K; ++i) {
            cin >> a[i];
        }
        int ans = 0;
        int j = 0;

        for (int i = 0; i < K; ++i) {
            while (j < i && a[j] + 5000 <= a[i]) {
                j++;
            }

            ans = max(ans, i - j + 1);
        }

        cout << "Case " << cnum << ": " << (K + ans) << '\n';
    }
    return 0;
}
