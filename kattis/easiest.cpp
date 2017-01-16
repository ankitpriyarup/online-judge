#include <iostream>

using namespace std;

int sum_digit(int x) {
    int ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }

    return ret;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        int target = sum_digit(n);
        for (int m = 11; m <= 100; ++m) {
            if (sum_digit(m * n) == target) {
                cout << m << '\n';
                break;
            }
        }
    }
    return 0;
}
