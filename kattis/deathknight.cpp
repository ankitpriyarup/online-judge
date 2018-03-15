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

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bool valid = true;
        for (int j = 0; j + 1 < s.size(); ++j) {
            valid &= !(s[j] == 'C' and s[j + 1] == 'D');
        }
        ans += valid;
    }

    cout << ans << '\n';
    
    return 0;
}
