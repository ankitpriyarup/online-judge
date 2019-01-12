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
    string s;
    cin >> n >> s;
    vector<int> f(3, 0);
    for (int i = 0; i < n; ++i) {
        ++f[s[i] - '0'];
    }

    int g = n / 3;
    // set the zeros as early as possible
    for (int i = 0; i < n; ++i) {
        int v = s[i] - '0';
        if (f[0] < g and f[v] > g) {
            s[i] = '0';
            ++f[0];
            --f[v];
        }
    }

    // set the twos as late as possible
    for (int i = n - 1; i >= 0; --i) {
        int v = s[i] - '0';
        if (f[2] < g and f[v] > g) {
            s[i] = '2';
            ++f[2];
            --f[v];
        }
    }

    // change excess twos to 1s from the beginning
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2' and f[1] < g and f[2] > g) {
            s[i] = '1';
            ++f[1];
            --f[2];
        }
    }

    // change excess 0s to 1s from the end
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0' and f[1] < g and f[0] > g) {
            s[i] = '1';
            ++f[1];
            --f[0];
        }
    }

    cout << s << '\n';


    return 0;
}
