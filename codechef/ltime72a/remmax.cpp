#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

string rev(const string& s) {
    string t;
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] != '0' or !t.empty()) {
            t.push_back(s[i]);
        }
    }

    if (t.empty())
        t = "0";
    return t;
}

string solve(string& s) {
    if (s.size() == 1) {
        return s;
    }
    int n = s.size();
    string ans = s;
    string best = rev(s);
    if (best.size() < n) {
        ans.clear();
        best.clear();
        for (int i = 0; i < n - 1; ++i) {
            ans.push_back('9');
            best.push_back('9');
        }
    }

    for (int i = 0; i < n; ++i) {
        char min_char = (i == 0) + '0';
        if (s[i] > min_char) {
            string t(s);
            --t[i];
            for (int j = i + 1; j < n; ++j) {
                t[j] = '9';
            }

            string w = rev(t);
            if (w.size() > best.size() or (w.size() == best.size() and w > best)) {
                return t;
            } else {
                return ans;
            }

            break;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        string s;
        cin >> s;
        string t = solve(s);
        cout << t << '\n';
    }
    
    return 0;
}
