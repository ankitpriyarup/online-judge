#include <iostream>

using namespace std;

int main() {
    int T, I, S, R;
    cin >> T;
    while (T-- > 0) {
        cin >> I;
        long long total_size = 0;
        for (int i = 0; i < I; ++i) {
            cin >> S >> R;
            total_size += S * R;
        }
        for (int i = 1; i <= 3; ++i) {
            long long square = 36LL * 36LL * i;
            cout << square / total_size;
            if (i != 3) {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
