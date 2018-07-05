#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

template <typename T>
struct pt {
    T x, y, z;
    pt operator+(const pt& other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    pt operator-(const pt& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    T dot(const pt& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
};

ll rad[2];
pt<ll> pos[2], vel[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << setprecision(10) << fixed;

    int T;
    cin >> T;
    while (T-- > 0) {
        for (int k = 0; k < 2; ++k) {
            cin >> pos[k].x >> pos[k].y >> pos[k].z;
            cin >> rad[k];
            cin >> vel[k].x >> vel[k].y >> vel[k].z;
        }

        auto p = pos[1] - pos[0];
        auto v = vel[1] - vel[0];
        ll r = rad[0] + rad[1];
        /* 
         * only dealing with p[1] and v[1] now
         *
         * Let R = r1 + r2
         * want to find min time when ||p + tv|| = R
         * (p + tv) (p + tv) = R^2
         * pp + 2 t pv + t^2 v v = R^2
         * a = vv
         * b = 2pv
         * c = pp - R^2
         * (-2 pv +- sqrt(4 (pv)^2 - 4 (pp - R^2) vv)) / (2 vv)
         */
        ll pv = p.dot(v);
        ll pp = p.dot(p);
        ll vv = v.dot(v);
        ll r2 = r * r;

        ll disc = 4LL * pv * pv - 4LL * (pp - r2) * vv;
        if (disc < 0 or vv == 0) {
            cout << "No collision\n";
        } else {
            double t0 = (-2.0 * pv - sqrt(disc)) / (2.0 * vv);
            double t1 = (-2.0 * pv + sqrt(disc)) / (2.0 * vv);
            if (t0 > t1) {
                swap(t0, t1);
            }

            constexpr double EPS = 1e-6;
            if (t1 < -EPS) {
                cout << "No collision\n";
            } else if (t0 < -EPS) {
                cout << t1 << '\n';
            } else {
                cout << t0 << '\n';
            }
        }
    }

    return 0;
}
