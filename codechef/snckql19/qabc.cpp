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

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        int n;
        scanf(" %d", &n);
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            scanf(" %lld", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf(" %lld", &b[i]);
        }

        for (int i = 0; i + 2 < n; ++i) {
            ll diff = b[i] - a[i];
            if (diff < 0) continue;
            a[i] += diff;
            a[i + 1] += 2LL * diff;
            a[i + 2] += 3LL * diff;
        }

        bool valid = true;
        for (int i = 0; i < n; ++i)
            valid &= a[i] == b[i];

        printf("%s\n", valid ? "TAK" : "NIE");
    }
    
    return 0;
}
