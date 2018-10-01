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

    if (s.size() == 3) {
        cout << 0 << '\n';
        return 0;
    }

    int n = s.size();
    vector<int> dp(8, 6);
    dp[0] = 0;

    string colors = "BGR";
    for (int i = 1; i < 8; ++i) {
        string t = "";
        for (int j = 0; j < 3; ++j) {
            if (i & (1 << j))
                t.push_back(colors[j]);
        }

        do {
            if (s.substr(0, t.size()) == t or s.substr(n - t.size(), t.size()) == t) {
                dp[i] = 1;
            } else if (s.find(t) != string::npos) {
                dp[i] = min(dp[i], 2);
            }
        } while (next_permutation(begin(t), end(t)));

        for (int ss = i; ss > 0; ss = (ss - 1) & i) {
            dp[i] = min(dp[i], dp[ss] + dp[i ^ ss]);
        }
    }

    cout << dp[7] << '\n';
    
    return 0;
}
