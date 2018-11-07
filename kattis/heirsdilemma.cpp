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

bool works(int x) {
    bool vis[10];
    for (int i = 0; i < 10; ++i)
        vis[i] = false;
    int nub = x;
    while (nub > 0) {
        int d = nub % 10;
        if (d == 0 or vis[d]) return false;
        vis[d] = true;
        nub /= 10;
    }
    for (int i = 0; i < 10; ++i)
        if (vis[i] and x % i != 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int lo, hi;
    scanf(" %d %d", &lo, &hi);
    int ans = 0;
    for (int x = lo; x <= hi; ++x) {
        if (works(x)) {
            ans++;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
