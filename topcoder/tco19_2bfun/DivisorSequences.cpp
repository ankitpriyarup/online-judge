#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

class DivisorSequences {
public:
    map<int, int> dp;
    vector<int> divisors(int n) {
        if (n <= 1) return {};
        vi res = {1};
        for (int i = 2; 1LL * i * i <= n; ++i) {
            if (n % i == 0) {
                res.push_back(i);
                if (i * i != n) {
                    res.push_back(n / i);
                }
            }
        }

        return res;
    }

    int longest(int n) {
        // length is at most 30, as smallest sequence is 1, 2, 4, 8, ...
        // last element has to be >= n / 2
        if (n == 1) {
            return 1;
        }
        if (dp.find(n) != end(dp))
            return dp[n];

        int ans = 1;
        for (int x : divisors(n)) {
            ans = max(ans, longest(x));
        }
        for (int x : divisors(n - 1)) {
            ans = max(ans, 1 + longest(x));
        }

        return dp[n] = ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    DivisorSequences ds;
    int n;
    cin >> n;
    cout << ds.longest(n) << '\n';

    return 0;
}
