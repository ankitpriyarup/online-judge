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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> stk;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() and stk.back() < a[i]) {
            ans = max(ans, a[i] ^ stk.back());
            stk.pop_back();
        }

        stk.push_back(a[i]);
    }

    stk.clear();
    reverse(begin(a), end(a));
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() and stk.back() < a[i]) {
            ans = max(ans, a[i] ^ stk.back());
            stk.pop_back();
        }

        stk.push_back(a[i]);
    }

    cout << ans << '\n';

    return 0;
}
