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

int modpow(int b, int e, int m) {
    if (e == 0) return 1 % m;
    if (e == 1) return b % m;
    int c = modpow(b, e / 2, m);
    int res = (1LL * c * c) % m;
    if (e & 1) return (1LL * res * b) % m;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    scanf(" %d %d %d", &n, &m, &k);
    int ans = 0;
    int x;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &x);
        if (modpow(x, m, k) == 0)
            ++ans;
    }
    printf("%d\n", ans);
    
    return 0;
}
