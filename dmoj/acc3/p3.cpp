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
#define sz(X) (int)(X).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<vector<int>>> occ(n, vector<vector<int>>(26));
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = (int)s[i].size() - 1; j >= 0; --j) {
            occ[i][s[i][j] - 'a'].push_back(j);
            // cout << "-- occ[" << i << "][" << (int)(s[i][j] - 'a') << "] += " << j << '\n';
        }
    }

    vector<int> p(n, 0);
    string ans;
    while (true) {
        bool added = false;

        for (char c = 'z'; c >= 'a'; --c) {
            // see if you can do it for all of them
            bool can_make = true;
            for (int i = 0; i < n; ++i) {
                while (!occ[i][c - 'a'].empty() and occ[i][c - 'a'].back() < p[i])
                    occ[i][c - 'a'].pop_back();

                can_make &= !occ[i][c - 'a'].empty() and occ[i][c - 'a'].back() >= p[i];
                if (!can_make) {
                    break;
                // cout << "-- cannot make " << c << " because of " << s[i] << '\n';
                }
            }

            if (can_make) {
                // cout << "-- ADDING " << c << '\n';
                added = true;
                for (int i = 0; i < n; ++i) {
                    p[i] = occ[i][c - 'a'].back() + 1;
                    occ[i][c - 'a'].pop_back();
                }

                ans.push_back(c);
                break;
            }
        }

        if (!added)
            break;
    }

    if (ans.empty())
        ans = "-1";

    cout << ans << '\n';

    return 0;
}
