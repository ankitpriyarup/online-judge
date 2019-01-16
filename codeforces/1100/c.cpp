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

    int n, r;

    cin >> n >> r;

    // say we have two circles
    // tangent to center
    //
    // tan(t/2) = R/(r + R)
    // t = 1/n * 2pi
    // sin(pi/n) = R/(r + R)
    // solve for R
    // (r + R) sin (pi / n) = R
    // r s + R s = R
    // r s = R (1 - s)
    // r s / (1 - s) = R

    constexpr double pi = 3.1415926535897932384626;
    double s = sin(pi / n);
    double ans = r * s / (1.0 - s);

    cout << setprecision(10) << fixed << ans << '\n';

    return 0;
}
