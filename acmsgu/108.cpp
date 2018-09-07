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

int digsum(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    scanf(" %d %d", &n, &k);
    constexpr int MAXN = 1e7;
    bitset<MAXN + 1> not_self;
    vector<int> selfs;
    for (int x = 1; x <= n; ++x) {
        int f = x + digsum(x);
        if (f <= MAXN) {
            not_self[f] = true;
        }

        if (!not_self[x]) {
            selfs.push_back(x);
        }
    }

    printf("%d\n", (int)selfs.size());

    int x;
    while (k-- > 0) {
        scanf(" %d", &x);
        --x;
        printf("%d ", selfs[x]);
    }
    
    return 0;
}
