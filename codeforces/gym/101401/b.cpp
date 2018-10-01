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

    string s;
    cin >> s;

    // number of :) after flipping first x is 
    // number of ): in prefix + (1 if s[0] == ':' and s[x] == ')) + number of :) in suffix
    int n = s.size();
    vector<int> pref(n, 0), suff(n, 0);
    for (int i = 1; i < n; ++i) {
        pref[i] += pref[i - 1];
        if (s[i - 1] == '(' and s[i] == ':')
            ++pref[i];
    }

    for (int i = n - 2; i >= 0; --i) {
        suff[i] += suff[i + 1];
        if (s[i] == ':' and s[i + 1] == ')')
            ++suff[i];
    }

    /*
    for (int x : pref)
        cout << x << ' ';
    cout << '\n';
    for (int x : suff)
        cout << x << ' ';
    cout << '\n';
    */

    int ans = max(pref[n - 1], suff[0]);
    for (int x = 1; x + 1 < n; ++x) {
        int cur = pref[x - 1] + suff[x] + (s[0] == ':' and s[x] == ')');
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    
    return 0;
}
