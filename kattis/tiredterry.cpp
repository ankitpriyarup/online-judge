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

    int n, p, d;
    cin >> n >> p >> d;

    vi a(2 * n + 1);
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        a[i + 1] = a[n + i + 1] = s[i] == 'Z';
    }
    for (int i = 1; i <= 2 * n; ++i) {
        a[i] += a[i - 1];
    }

    int tired = 0;
    for (int i = n + 1; i <= 2 * n; ++i) {
        if (a[i] - a[i - p] < d) {
            ++tired;
        }
    }

    cout << tired << '\n';
    
    return 0;
}
