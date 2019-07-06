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

    vi freq(26, 0);
    for (char c : s) {
        ++freq[c - 'A'];
    }

    vi odds;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2) {
            odds.push_back(i);
        }
    }

    if (odds.size() > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    string t;
    for (int i = 0; i < 26; ++i) {
        if (!odds.empty() and i == odds[0]) {
            continue;
        }

        for (int j = 0; 2 * j < freq[i]; ++j) {
            t.push_back(i + 'A');
        }
    }

    if (!odds.empty()) {
        for (int j = 0; j < freq[odds[0]]; ++j) {
            t.push_back(odds[0] + 'A');
        }
    }
    for (int i = 25; i >= 0; --i) {
        if (!odds.empty() and i == odds[0]) {
            continue;
        }

        for (int j = 0; 2 * j < freq[i]; ++j) {
            t.push_back(i + 'A');
        }
    }


    cout << t << '\n';

    return 0;
}
