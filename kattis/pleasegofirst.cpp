#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int solve(const string& s) {

    int n = s.size();
    vi last(256, -1);
    for (int i = 0; i < n; ++i) {
        last[s[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += 5 * (last[s[i]] - i);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi last(256, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i]] = i;
        }

        int orig = solve(s);
        sort(all(s), [&](const char& a, const char& b) {
            return last[a] < last[b];
        });

        cout << (orig - solve(s)) << '\n';
    }
    
    return 0;
}
