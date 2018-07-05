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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string dashes(40, '-');

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int r, p, d;
        cin >> r >> p >> d;
        vector<string> names(r);
        vector<double> weights(r), pcts(r);

        int main_ingred;
        for (int i = 0; i < r; ++i) {
            cin >> names[i] >> weights[i] >> pcts[i];
            if (pcts[i] == 100.0) {
                main_ingred = i;
            }
        }

        double factor = static_cast<double>(d) / p;
        double scaled_main  = weights[main_ingred] * factor;

        cout << "Recipe # " << test_case << '\n';
        for (int i = 0; i < r; ++i) {
            double ans = scaled_main * pcts[i] / 100.0;
            cout << setprecision(10) << fixed << names[i] << ' ' << ans << '\n';
            // cout << fixed << setprecision(10) << names[i] << ' ' << ans << '\n';
        }

        cout << dashes << '\n';
    }
    
    return 0;
}
