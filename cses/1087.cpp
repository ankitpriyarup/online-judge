#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int idx(char c) {
    if (c == 'A')
        return 0;
    else if (c == 'T')
        return 1;
    else if (c == 'C')
        return 2;
    else if (c == 'G')
        return 3;

    assert(false);
    return 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    vector<vi> dp(n + 1, vi(4, 1));
    // dp[i][j] = min size subsequence ending with char j that does not appear in
    for (int i = 0; i < n; ++i) {

    }

    return 0;
}
