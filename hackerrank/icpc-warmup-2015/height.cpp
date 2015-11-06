#include <iostream>

using namespace std;

int main() {
    int T, K;
    int a[20];
    cin >> T;
    while (T-- > 0) {
        cin >> K;
        for (int i = 0; i < 20; ++i) {
            cin >> a[i];
        }

        int ans = 0;

        for (int i = 1; i < 20; ++i) {
            for (int j = 0; j < i; ++j) {
                if (a[i] < a[j]) {
                    ans++;
                }
            }
        }

        cout << K << " " << ans << '\n';
    }
    return 0;
}
