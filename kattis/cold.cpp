#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x, ans = 0;
    while (n-- > 0) {
        cin >> x;
        if (x < 0) {
            ++ans;
        }
    }

    cout << ans << '\n';
    return 0;
}
