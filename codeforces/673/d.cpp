#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, k;
int a, b, c, d;
int nodes[1003];

int main() {
    cin >> n >> k;
    cin >> a >> b >> c >> d;
    if (n == 4 or k < n + 1) {
        cout << -1 << '\n';
        return 0;
    }

    int nn = 1;
    for (int i = 3; i <= n - 2; ++i) {
        while (nn == a || nn == b || nn == c || nn == d) ++nn;
        nodes[i] = nn;
        ++nn;
    }

    cout << a << ' ' << c;
    for (int i = 3; i <= n - 2; ++i) {
        cout << ' ' << nodes[i];
    }
    cout << ' ' << d << ' ' << b << '\n';

    cout << c << ' ' << a;
    for (int i = 3; i <= n - 2; ++i) {
        cout << ' ' << nodes[i];
    }
    cout << ' ' << b << ' ' << d << '\n';

    return 0;
}
