#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr double PI = 3.14159265358979;
constexpr double EPS = 1e-8;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        int s, r;
        scanf(" %d %d", &s, &r);

        // cos(t/2) = (s/2) / r
        // t/2 = acos((s/2) / r)
        // t = 2 * acos((s/2) / r)
        if (s / 2.0 >= r) {
            printf("%.2f\n", PI * r * r);
        } else if (r >= s / 2.0 * sqrt(2) - EPS) {
            printf("%.2f\n", 1.0 * s * s);
        } else {
            double theta = 2.0 * acos((s / 2.0) / r);
            double area = PI * r * r;
            double cap = area * theta / 2.0 / PI - 0.5 * r * r * sin(theta);
            area -= 4.0 * cap;

            printf("%.2f\n", area);
        }
    }

    return 0;
}
