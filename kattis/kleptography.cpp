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

    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    string ans(n + m, ' ');
    for (int i = 0; i < n; ++i) {
        ans[m + i] = s[i];
    }
    for (int i = m - 1; i >= n; --i) {
        ans[i] = (-ans[i + n] + t[i] + 26) % 26 + 'a';
    }

    cout << ans.substr(n) << '\n';
    
    return 0;
}
