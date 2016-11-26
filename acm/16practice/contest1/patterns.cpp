#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int T, I, S, R;
    cin >> T;
    while (T-- > 0) {
        cin >> I;
        long long total = 0;
        for (int i = 0; i < I; ++i) {
            cin >> S >> R;
            total += S * R;
        }
        long long a1 = 36 * 36 / total;
        long long a2 = (2 * 36 * 36) / total;
        long long a3 = 3 * 36 * 36 / total;

        cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
    }
}
