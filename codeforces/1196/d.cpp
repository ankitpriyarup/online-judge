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
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q-- > 0) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R')
                a[i] = 0;
            else if (s[i] == 'G')
                a[i] = 1;
            else
                a[i] = 2;
        }

        vector<vector<int>> freq(3, vector<int>(3, 0));
        for (int i = 0; i < k; ++i) {
            ++freq[i % 3][a[i]];
        }

        vector<int> g(3, k / 3);
        for (int i = 0; i < k % 3; ++i)
            ++g[i];

        int ans = 1e9 + 7;
        for (int d = 0; d < 3; ++d) {
            int tot = 0;
            for (int i = 0; i < 3; ++i) {
                tot += freq[i][(i + d) % 3];
            }

            ans = min(ans, k - tot);
        }

        for (int i = k; i < n; ++i) {
            --freq[(i - k) % 3][a[i - k]];
            ++freq[i % 3][a[i]];
            for (int d = 0; d < 3; ++d) {
                int tot = 0;
                for (int i = 0; i < 3; ++i) {
                    tot += freq[i][(i + d) % 3];
                }

                ans = min(ans, k - tot);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
