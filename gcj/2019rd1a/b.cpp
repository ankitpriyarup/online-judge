#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int mods[] = {8, 9, 5, 7, 11, 13, 17};
int sums[7];

// from kactl
ll gcd(ll a, ll b) { return __gcd(a, b); }

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (b) { ll d = euclid(b, a % b, y, x);
		return y -= a/b * x, d; }
	return x = 1, y = 0, a;
}

ll chinese(ll a, ll m, ll b, ll n) {
    ll x, y;
    euclid(m, n, x, y);
	ll ret = a * (y + m) % m * n + b * (x + n) % n * m;
    if (ret >= m * n) ret -= m * n;
    return ret;
}

int main() {
    constexpr int B = 18;

    int T, n, m;
    cin >> T >> n >> m;

    while (T-- > 0) {
        for (int j = 0; j < 7; ++j) {
            for (int i = 0; i < B; ++i) {
                cout << mods[j] << " \n"[i == B - 1];
            }
            cout.flush();

            sums[j] = 0;
            for (int i = 0; i < B; i++) {
                int x;
                cin >> x;
                if (x == -1) {
                    return 0;
                }

                sums[j] += x;
            }
        }

        ll res = sums[0];
        ll mod = mods[0];
        for (int j = 1; j < 7; ++j) {
            res = chinese(res, mod, sums[j], mods[j]);
            mod *= mods[j];
        }

        cout << res << '\n';
        cout.flush();
    }
    
    return 0;
}
