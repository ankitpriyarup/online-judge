#include <iostream>

using namespace std;

void soroban(int n) {
    if (n >= 5) {
        cout << "-O|";
    } else {
        cout << "O-|";
    }

    n %= 5;
    for (int i = 0; i < n; ++i) {
        cout << "O";
    }

    cout << '-';

    for (int i = n + 1; i < 5; ++i) {
        cout << 'O';
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "O-|-OOOO\n";
    } else {
        while (n > 0) {
            soroban(n % 10);
            n /= 10;
        }
    }
    return 0;
}
