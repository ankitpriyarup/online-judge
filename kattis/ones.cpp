#include <iostream>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        int v = n > 1;
        int ans = 1;

        while (v != 0) {
            v *= 10;
            v += 1;
            v %= n;

            ++ans;
        }

        cout << ans << '\n';
    }

    return 0;
}
