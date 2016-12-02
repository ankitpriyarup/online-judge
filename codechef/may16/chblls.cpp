#include <iostream>

using namespace std;

int main() {
    cout << 1 << '\n';
    cout << "3 1 1 2\n";
    cout << "3 3 3 4\n";
    cout.flush();
    int resp;
    cin >> resp;
    int ans;
    if (resp <= 0) {
        ans = 5 + resp;
    } else {
        ans = 3 - resp;
    }
    cout << 2 << '\n';
    cout << ans << '\n';
    cout.flush();
    return 0;
}
