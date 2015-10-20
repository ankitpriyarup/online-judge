#include <iostream>

using namespace std;

int main() {
    int T, N;
    cin >> T;

    while (T-- > 0) {
        cin >> N;

        if (N >= 2) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
    return 0;
}
