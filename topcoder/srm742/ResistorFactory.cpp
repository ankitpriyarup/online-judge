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

constexpr double EPS = 1e-9;

class ResistorFactory {
public:
    vector<int> construct(long long nano_ohms) {
        double ohms = nano_ohms / 1e9;

        if (ohms < EPS)
            return {};

        vector<int> vec;
        for (int i = 1; i <= 31; ++i) {
            vec.push_back(i - 1);
            vec.push_back(i - 1);
            vec.push_back(0);
        }

        vec.push_back(0);
        vec.push_back(0);
        vec.push_back(1);
        for (int i = 33; i <= 62; ++i) {
            vec.push_back(i - 1);
            vec.push_back(i - 1);
            vec.push_back(1);
        }

        vector<int> needed;
        for (ll i = 31; i >= 0; --i) {
            ll x = (1LL << i);
            if (x <= ohms) {
                ohms -= x;
                needed.push_back((int) i);
            }
        }

        for (ll i = 32; i <= 62; ++i) {
            double res = 1.0 / (1LL << (i - 31));
            if (res <= ohms) {
                ohms -= res;
                needed.push_back((int) i);
            }
        }

        assert(!needed.empty());
        if (needed.size() == 1) {
            needed.push_back(62);
        }

        int id = 63;
        vec.push_back(needed[0]);
        vec.push_back(needed[1]);
        vec.push_back(0);
        for (int i = 2; i < needed.size(); ++i) {
            vec.push_back(id++);
            vec.push_back(needed[i]);
            vec.push_back(0);
        }

        return vec;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll g;
    cin >> g;
    ResistorFactory rf;
    auto ans = rf.construct(g);
    vector<double> res = {1.0};
    for (int i = 0; i < ans.size(); i += 3) {
        int x = ans[i];
        int y = ans[i + 1];
        int z = ans[i + 2];
        double r1 = res[x];
        double r2 = res[y];
        if (z) {
            // 1 / r = 1 / r1 + 1 / r2
            double r = 1.0 / (1.0 / r1 + 1.0 / r2);
            res.push_back(r);
        } else {
            res.push_back(r1 + r2);
        }

        // cout << "Add resistor of rez " << res.back() << '\n';
    }
    cout << "{";
    for (int v : ans) {
        cout << v << ", ";
    }
    cout << "}\n";

    return 0;
}
