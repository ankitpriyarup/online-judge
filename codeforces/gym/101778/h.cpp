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
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;
        string str;
        cin >> str;

        int bad = 0;
        for (int s = 0, e = n - 1; s < e; ++s, --e)
            bad += str[s] != str[e];

        char c;
        int p;
        int ans = 0;
        while (m-- > 0) {
            cin >> p >> c;
            --p;
            int o = n - 1 - p;

            bool old_bad = str[o] != str[p];
            str[p] = c;
            bool new_bad = str[o] != str[p];
            if (old_bad and !new_bad)
                --bad;
            else if (!old_bad and new_bad)
                ++bad;

            if (bad == 0)
                ++ans;
        }

        printf("%d\n", ans);
    }
    
    return 0;
}
