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

    vector<string> s(2);
    cin >> s[0] >> s[1];
    int n = s[0].size();

    vi freq(4, 0);
    for (int i = 0; i < n; ++i) {
        int x = 0;
        if (s[0][i] == '#') x |= 2;
        if (s[1][i] == '#') x |= 1;
        ++freq[x];
    }

    // cout << freq[0] << ' ' << freq[1] << ' ' << freq[2] << ' ' << freq[3] << '\n';
    if (freq[3] == 0 and freq[1] > 0 and freq[2] > 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    {
        string t(n, '.');
        for (int j = 0; j < freq[2] + freq[3]; ++j) {
            t[j] = '#';
        }
        cout << t << '\n';
    }

    {
        string t(n, '.');
        for (int j = 0; j < freq[1] + freq[3]; ++j) {
            t[j + freq[2]] = '#';
        }
        cout << t << '\n';
    }

    return 0;
}
