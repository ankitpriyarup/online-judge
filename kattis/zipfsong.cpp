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

    int n, m;
    cin >> n >> m;

    vector<string> names(n);
    vector<pair<ll, int>> f;
    ll tot = 0LL;
    ll plays;

    for (int i = 1; i <= n; ++i) {
        cin >> plays >> names[i - 1];
        f.emplace_back(i * plays, -i);
        tot += plays;
    }


    /*
     * What are the distributions/
     *
     * 2 songs:
     * 1 + 1/2 = 3 / 2
     * 1 + 1/2 + 1/3 = 11/6
     * ! + 1/2 + 1/3 + 1/4 = 25/12
     * ... just use the fractions
     *
     * f_i / z_i = f_i / (1 / i) = i * f_i
     */

    sort(begin(f), end(f));
    reverse(begin(f), end(f));
    for (int i = 0; i < m; ++i) {
        cout << names[-f[i].second - 1] << '\n';
    }
    
    return 0;
}
