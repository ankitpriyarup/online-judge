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

    vector<int> seen(n + 1);
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        seen[x] = true;
    }

    int ans = n;
    for (int i = 1; i <= n; ++i) {
        ans -= seen[i];
    }
    cout << ans << '\n';
    
    return 0;
}
