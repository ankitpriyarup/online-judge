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
    freopen("cowdate.in", "r", stdin);
    freopen("cowdate.out", "w", stdout);

    int n;
    cin >> n;

    constexpr int CAP = 1000000;
    vector<ld> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        p[i] /= CAP;
    }

    vector<ld> q_sum(n + 1);
    vector<ld> frac_sum(n + 1);
    q_sum[0] = 1.0;
    frac_sum[0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        ld q = (1.0 - p[i]);
        q_sum[i] = q_sum[i - 1] * q;
        frac_sum[i] = frac_sum[i - 1] + p[i] / q;
    }
    /**
     * let q[i] = 1 - p[i]
     * Probability of exactly 1
     * sum over everything in the list of
     * prod q[i] * sum p[i] / q[i]
     *
     * Using prefix sums it's
     * q_sum[i] / q_sum[j] * (frac_sum[i] - frac_sum[j])
     * (q_sum[i] * frac_sum[i] - q_sum[i] * frac_sum[j]) / q_sum[j]
     * Want to find the j that maximizes the above for a given i
     * maximize (a - bx) / y
     */
    ld ans = 0.0;
    auto f = [&](int i, int j) {
        ld res = q_sum[i] / q_sum[j] * (frac_sum[i] - frac_sum[j]);
        ans = max(ans, res);
        return res;
    };
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        while (j + 1 < i and f(i, j + 1) > f(i, j))
            ++j;
    }

    cout << static_cast<int>(CAP * ans) << '\n';

    return 0;
}
