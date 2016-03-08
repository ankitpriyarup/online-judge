#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    bool solved = false;
    for (int x = 0; !solved and a * x <= c; ++x) {
        if ((c - a * x) % b == 0) {
            solved = true;
        }
    }

    cout << (solved ? "Yes" : "No") << '\n';

    return 0;
}
