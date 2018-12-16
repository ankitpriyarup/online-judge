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
    vector<vector<int>> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        f[a[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        reverse(begin(f[i]), end(f[i]));
    }

    vector<int> ans(n, 0);
    int used = 0;
    int id = 1;
    for (int i = 0; i < n; ++i) {
        if (ans[i] != 0) continue;
        // say person i was wearing hat i. Then the next n people with the same freq had to wear that
        int with_hat = n - a[i];
        if (f[a[i]].size() < with_hat) {
            cout << "Impossible\n";
            return 0;
        }

        while (with_hat-- > 0) {
            ++used;
            ans[f[a[i]].back()] = id;
            f[a[i]].pop_back();
        }
        ++id;
    }

    if (used != n) {
        cout << "Impossible\n";
        return 0;
    }

    cout << "Possible\n";
    for (int x : ans)
        cout << x << " ";
    
    return 0;
}
