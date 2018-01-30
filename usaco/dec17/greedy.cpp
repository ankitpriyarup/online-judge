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

bool works(const vector<int>& a, int x) {
    // Does cow x get a gift?
    vector<int> v(begin(a), begin(a) + x);
    sort(begin(v), end(v));
    int herd = a.size() - x - 1;
    for (int y : v) {
        if (y <= herd) {
            ++herd;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);

    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int lo = 0;
    int hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (works(a, mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%d\n", n - hi);

    return 0;
}
