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

    constexpr int MOD = 1e9 +  7;
    vector<int> ans = {1, 0, 1};
    for (int i = 3; i <= 20; ++i) {
        int x = ans[i - 2] + ans[i - 1];
        if (x >= MOD)
            x -= MOD;
        x = 1LL * x * (i - 1) % MOD;
        ans.push_back(x);
    }

    int n;
    cin >> n;
    cout << ans[n] << '\n';
    
    return 0;
}
