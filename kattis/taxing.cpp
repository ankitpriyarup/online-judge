#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXB = 24;
int B;
double s[MAXB], p[MAXB];
constexpr double EPS = 0.0;

double tax(double income) {
    double rem = income;
    double tax = 0.0;
    for (int i = 0; rem > EPS and i < B; ++i) {
        double take = min(s[i], rem);
        tax += take * p[i];
        rem -= take;
    }

    if (rem > EPS) {
        tax += rem * p[B];
    }

    return income - tax;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> B;
    for (int i = 0; i < B; ++i) {
        cin >> s[i] >> p[i];
        p[i] /= 100.0;
    }
    cin >> p[B];
    p[B] /= 100.0;

    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    while (T-- > 0) {
        double earned, goal;
        cin >> earned >> goal;

        double lo = 0.0;
        double hi = 1e15;

        double base = tax(earned);

        for (int iter = 0; iter < 200; ++iter) {
            double mid = (lo + hi) / 2.0;
            double rem = tax(earned + mid);
            if (rem >= base + goal) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        cout << hi << '\n';
    }
    
    return 0;
}
