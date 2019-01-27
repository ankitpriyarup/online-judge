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
    string s;
    cin >> s;

    vi a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] == 'B' ? 0 : (s[i] == 'G' ? 1 : 2);
    }

    int changes = n + n;
    tuple<int, int, int> winner;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            for (int k = 0; k < 3; ++k) {
                if (i == k or j == k) continue;

                int c[] = {i, j, k};
                int cur = 0;
                for (int idx = 0; idx < n; ++idx) {
                    if (a[idx] != c[idx % 3]) {
                        ++cur;
                    }
                }

                if (cur < changes) {
                    changes = cur;
                    winner = make_tuple(i, j, k);
                }
            }
        }
    }

    cout << changes << '\n';
    
    int c[] = {get<0>(winner), get<1>(winner), get<2>(winner)};
    for (int i = 0; i < n; ++i) {
        s[i] = "BGR"[c[i % 3]];
    }
    cout << s << '\n';

    return 0;
}
