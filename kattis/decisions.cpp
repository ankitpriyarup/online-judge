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

constexpr int MAXN = 1 << 19;
constexpr int LOGN = 19;
int n;

// [x, y)
int solve(const vector<int>& v) {
    if (v.size() <= 1)
        return 1;

    bool all_eq = true;
    for (int x : v)
        all_eq &= x == v[0];

    if (all_eq)
        return 1;

    vector<int> a;
    vector<int> b;
    for (int i = 0; i < v.size(); i += 2) {
        a.push_back(v[i]);
        b.push_back(v[i + 1]);
    }

    return 1 + solve(a) + solve(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    n = 1 << n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }

    printf("%d\n", solve(v));

    return 0;
}
