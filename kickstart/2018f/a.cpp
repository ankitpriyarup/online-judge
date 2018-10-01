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

// Solve a single case and print it (no newline at the end).
void solve() {
    int n;
    cin >> n;

    string a, b;
    cin >> a >> b;

    vector<vector<vector<int>>> freq(2, vector<vector<int>>(n + 1, vector<int>(26, 0)));

    for (int i = 0; i < n; ++i) {
        ++freq[0][i + 1][a[i] - 'A'];
        ++freq[1][i + 1][b[i] - 'A'];
    }

    for (int k = 0; k < 2; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 26; ++j) {
                freq[k][i][j] += freq[k][i - 1][j];
            }
        }
    }

    map<vector<int>, int> a_subs;
    for (int e = 1; e <= n; ++e) {
        for (int s = 0; s < e; ++s) {
            vector<int> sub(26, 0);
            for (int j = 0; j < 26; ++j) {
                sub[j] = freq[0][e][j] - freq[0][s][j];
            }

            a_subs[sub] += 1;
        }
    }

    set<vector<int>> seen;
    ll ans = 0LL;
    for (int e = 1; e <= n; ++e) {
        for (int s = 0; s < e; ++s) {
            vector<int> sub(26, 0);
            for (int j = 0; j < 26; ++j) {
                sub[j] = freq[1][e][j] - freq[1][s][j];
            }

            if (seen.count(sub))
                continue;

            ans += a_subs[sub];
            seen.insert(sub);
        }
    }


    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cout << "Case #" << case_num << ": ";
        solve();
        cout << '\n';
    }
    
    return 0;
}
