#include <iostream>

using namespace std;

int main() {
    int N, x;
    cin >> N;
    while (N-- > 0) {
        cin >> x;
        cout << x << " is " << (x % 2 ? "odd" : "even") << '\n';
    }
    return 0;
}
