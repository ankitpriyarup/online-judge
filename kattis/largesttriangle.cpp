#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using pt = pair<ll, ll>;

ll ccw(const pt& a, const pt& b, const pt& c) {
    ll x1 = b.first - a.first;
    ll y1 = b.second - a.second;
    ll x2 = c.first - a.first;
    ll y2 = c.second - a.second;

    return x1 * y2  - x2 * y1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pt> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].first >> pts[i].second;
    }
    sort(all(pts));
    pts.erase(unique(all(pts)), end(pts));

    n = pts.size();
    vector<pt> hull;
    if (pts.size() <= 2) {
        hull = pts;
    } else {
        for (int k = 0; k < 2; ++k) {
            int start = hull.size();
            for (int i = 0; i < n; ++i) {
                while (hull.size() >= start + 2 and 
                        ccw(hull[hull.size() - 2], hull[hull.size() - 1], pts[i]) < 0) {
                    hull.pop_back();
                }

                hull.push_back(pts[i]);
            }

            hull.pop_back();
            reverse(all(pts));
        }
    }

    n = hull.size();
    ll ans = 0LL;
    for (int a = 0; a < n; ++a) {
        int c = a;
        for (int b = a + 1; b < n; ++b) {
            while (abs(ccw(hull[a], hull[b], hull[c])) < abs(ccw(hull[a], hull[b], hull[(c + 1) % n]))) {
                c = (c + 1) % n;
            }
            ans = max(ans, abs(ccw(hull[a], hull[b], hull[c])));
        }
    }

    cout << (ans / 2) << "." << (ans & 1 ? "5" : "0") << '\n';
    
    return 0;
}
