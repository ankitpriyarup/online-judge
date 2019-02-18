#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool is_pal(const string& s) {
    int x = 0;
    int y = s.size();
    --y;
    while (x < y) {
        if (s[x] != s[y])
            return false;
        ++x;
        --y;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    // impossible if all the same or all the same except center
    bool is_odd = n & 1;
    vi freq(26, 0);
    for (int i = 0; i < n; ++i) {
        ++freq[s[i] - 'a'];
    }
    if (is_odd) {
        --freq[s[n / 2] - 'a'];
    }
    int distinct = 0;
    for (int j = 0; j < 26; ++j)
        distinct += freq[j] > 0;
    if (distinct == 1) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        string t = s.substr(i, n - i) + s.substr(0, i);
        if (s != t and is_pal(t)) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 2 << '\n';
    return 0;
}
