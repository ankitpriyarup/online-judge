#include <iostream>

using namespace std;

long long n;

long long pow() {
    long long p = 1;
    while (p <= n) {
        p <<= 1;
    }

    return p - 1;
}

long long calc() {
    long long t = n * (n + 1) / 2;
    return t - 2LL * pow();
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> n;
        cout << calc() << '\n';
    }
}
