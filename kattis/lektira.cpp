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
    int n = s.size();

    string ans = s;
    for (int a = 1; a < n; ++a) {
        for (int b = 1; a + b < n; ++b) {
            int c = n - a - b;
            string x = s.substr(0, a);
            string y = s.substr(a, b);
            string z = s.substr(a + b, c);
            reverse(begin(x), end(x));
            reverse(begin(y), end(y));
            reverse(begin(z), end(z));

            ans = min(ans, x + y + z);
        }
    }
    
    cout << ans << '\n';
    return 0;
}
