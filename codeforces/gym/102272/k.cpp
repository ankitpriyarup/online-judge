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
    vector<pair<int, double>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(all(a), [](const pair<int, double>& p1, const pair<int, double>& p2) {
        int ta, tb;
        double pa, pb;
        tie(ta, pa) = p1;
        tie(tb, pb) = p2;

        // what's the sum of waiting times here?
        double ab = 0.0;
        double ba = 0.0;
        // both stay
        ab += pa * pb * (ta + ta + tb);
        ba += pa * pb * (tb + tb + ta);

        // a stays, b leaves
        ab += pa * (1.0 - pb) * (ta + ta);
        ba += pa * (1.0 - pb) * (ta);

        // a leaves, b stays
        ab += (1.0 - pa) * pb * (tb);
        ba += (1.0 - pa) * pb * (tb + tb);
        return ab < ba;
    });

    double ans = 0.0;
    double cur = 0.0;
    for (int i = 0; i < n; ++i) {
        cur += a[i].first * a[i].second;
        ans += cur;
    }

    cout << fixed << setprecision(10) << (ans / n) << '\n';

    return 0;
}
