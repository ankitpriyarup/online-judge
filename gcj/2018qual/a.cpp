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

ll score(const string& s) {
    ll power = 1LL;
    ll res = 0LL;
    for (const auto& c : s) {
        if (c == 'C')
            power *= 2LL;
        else
            res += power;
    }

    return res;
}

bool fix(string& s) {
    int n = s.size();
    for (int i = n - 1; i >= 1; --i) {
        if (s[i] == 'S' and s[i - 1] == 'C') {
            s[i - 1] = 'S';
            s[i] = 'C';
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    ll d;
    string s;
    int tc = 1;
    while (T-- > 0) {
        cin >> d >> s;
        int ans = 0;
        while (score(s) > d) {
            if (fix(s)) {
                ++ans;
            } else {
                ans = -1;
                break;
            }
        }

        if (ans >= 0)
            cout << "Case #" << tc++ << ": " << ans << '\n';
        else
            cout << "Case #" << tc++ << ": " << "IMPOSSIBLE" << '\n';
    }

    return 0;
}
