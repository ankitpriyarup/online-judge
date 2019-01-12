#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool works(const string& s, int v) {
    int n = s.size();
    //  [: |||| :]
    int i = 0;
    int p = 0;
    string t = "[::]";
    for (; p < 2 and i < n; ++i) {
        if (s[i] == t[p]) {
            ++p;
        }
    }

    if (p < 2)
        return false;

    int j = n - 1;
    p = 3;
    for (; p > 1 and j < n; --j) {
        if (s[j] == t[p]) {
            --p;
        }
    }

    if (p >= 2)
        return false;

    cout << v << '\n';
    cout << i << ", " << j << '\n';

    int f = 0;
    for (int k = i - 1; k <= j; ++k) {
        if (s[k] == '|') {
            ++f;
        }
    }

    return f >= v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    vector<char> stk;
    int n = s.size();
    vi dp(n, n);
    vi p(n, 0);

    vi valid_pref(n, 0), valid_suff(n, 0);

    for (int i = 0; i < n; ++i) {
        if (stk.empty() and s[i] == '[') {
            stk.push_back(s[i]);
        } else if (stk.size() == 1 and s[i] == ':') {
            stk.push_back(s[i]);
            valid_pref[i] = true;
        }

        if (s[i] == '|') {
            ++p[i];
        }

        if (i) {
            p[i] += p[i - 1];
            valid_pref[i] |= valid_pref[i - 1];
        }
    }

    stk.clear();
    for (int i = n - 1; i >= 0; --i) {
        if (stk.empty() and s[i] == ']') {
            stk.push_back(s[i]);
        } else if (stk.size() == 1 and s[i] == ':') {
            stk.push_back(s[i]);
            valid_suff[i] = true;
        }

        if (i < n - 1)
            valid_suff[i] |= valid_suff[i + 1];
    }

    int i = 0;
    while (!valid_pref[i])
        ++i;
    int j = n -1;
    while (!valid_suff[j]) {
        --j;
    }

    if (i >= j) {
        cout << "-1\n";
        return 0;
    }

    cout << (4 + p[j] - p[i]) << '\n';

    return 0;
}
