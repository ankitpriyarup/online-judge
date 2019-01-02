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

    int T;
    cin >> T;
    int n, x;
    while (T-- > 0) {
        cin >> n;
        map<int, int> last;
        int l = -1;
        int ans = 0;
        for (int r = 0; r < n; ++r) {
            cin >> x;
            if (last.find(x) != end(last)) {
                l = max(l, last[x]);
            }

            ans = max(ans, r - l);
            last[x] = r;
        }

        cout << ans << '\n';
    }
    
    return 0;
}
