#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    // given two polynomials in base 26, average them?
    // basically write out bigint add and divide i guess
    //
    // az
    // bf
    //
    // 0 25
    // 1 5
    // 1 30
    // 2 4
    // 1 2
    //
    // afogk
    // asdji
    //
    // 0 5 14 6 10
    // 0 18 3 9 8
    // 0 23 17 15 18
    // 0 11 21 20 22
    //
    // alvuw

    vi c(n + 1);
    for (int i = 0; i < n; ++i) {
        c[i + 1] = s[i] - 'a' + t[i] - 'a';
    }
    /*
    for (int i = 0; i <= n; ++i) {
        cout << c[i] << ' ';
    } cout << '\n';
    */

    for (int i = n; i; --i) {
        while (c[i] >= 26) {
            c[i] -= 26;
            ++c[i - 1];
        }
    }

    /*
    for (int i = 0; i <= n; ++i) {
        cout << c[i] << ' ';
    } cout << '\n';
    */

    assert(c[n] % 2 == 0);
    for (int i = n; i >= 0; --i) {
        if (c[i] % 2 == 1) {
            c[i + 1] += 13;
        }
        c[i] >>= 1;
    }

    /*
    for (int i = 0; i <= n; ++i) {
        cout << c[i] << ' ';
    } cout << '\n';
    */

    string res;
    for (int i = 1; i <= n; ++i) {
        res.push_back(c[i] + 'a');
    }
    cout << res << '\n';

    return 0;
}
