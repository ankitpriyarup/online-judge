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
using cd = complex<long double>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<cd> ans = {1};
    for (int i = 1; i < 100; ++i) {
        cd res = pow(cd(0, 1), ans.back());
        ans.push_back(res);
    }

    ll x;
    scanf("%lld", &x);

    if (x < ans.size()) {
        printf("%.17Lf\n%.17Lf\n", ans[x].real(), ans[x].imag());
    } else {
        printf("%.17Lf\n%.17Lf\n", ans.back().real(), ans.back().imag());
    }
    
    return 0;
}
