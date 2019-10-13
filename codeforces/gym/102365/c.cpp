#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    int n;
    cin >> n;
    int a = 1;
    int b = 2;
    for (int c = 3; c <= n; ++c) {
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        int resp;
        cin >> resp;
        if (resp) {
            b = c;
        }
    }

    cout << "! " << b << endl;
    
    return 0;
}
