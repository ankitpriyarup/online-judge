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
    map<string, int> occ;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        cout << occ[s] << '\n';

        string t = "";
        for (int j = 0; j + 1 < s.size(); ++j) {
            t += s[j];
            ++occ[t];
        }
    }

    return 0;
}
