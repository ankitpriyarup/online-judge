#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;

    long long tx = 1;
    long long ax = 1;

    long long t, a;
    for (int i = 0; i < n; ++i) {
        cin >> t >> a;
        long long factor = 1;
        factor = max(factor, (tx / t) + (tx % t == 0 ? 0 : 1));
        factor = max(factor, (ax / a) + (ax % a == 0 ? 0 : 1));

        tx = t * factor;
        ax = a * factor;
    }

    cout << (tx + ax) << '\n';

    return 0;
}
