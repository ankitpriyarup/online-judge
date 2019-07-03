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

    // 1000000005 = 6
    // 9999999995 = 6
    // dp[i][j] = min cost to handle prefix up to i with / without a carry

    int n = s.size();
    int no_carry = 0;
    int carry = 1;
    for (int i = 0; i < n; ++i) {
        int d = s[i] - '0';

        int nnc = min(d + no_carry, 10 - d + carry);
        int nc = min(d + 1 + no_carry, 10 - d - 1 + carry);

        no_carry = nnc;
        carry = nc;
    }

    cout << no_carry << '\n';
    
    return 0;
}
