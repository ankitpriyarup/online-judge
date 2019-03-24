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

    string s;
    cin >> s;
    vector<string> a;
    {
        int n = s.size();
        int start = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '+') {
                a.push_back(s.substr(start, i - start));
                start = i + 1;
            }
        }
        a.push_back(s.substr(start, n - start));
    }

    int n = a.size();
    set<ll> found;
    for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
        vector<string> b;
        b.push_back(a[0]);
        for (int i = 1; i < n; ++i) {
            if (mask & (1 << (i - 1))) {
                b.back() += a[i];
            } else {
                b.push_back(a[i]);
            }
        }

        ll res = 0;
        for (const string& x : b) {
            res += stoll(x);
        }

        found.insert(res);
    }

    cout << found.size() << '\n';
    
    return 0;
}
