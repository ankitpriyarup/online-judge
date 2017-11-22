#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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

constexpr int MAXN = 1e6 + 6;
int n;
int keys[MAXN];
int vals[MAXN];
vector<int> ukeys;
bool used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        keys[i] = a;
        vals[i] = b;

        ukeys.push_back(a);
    }

    sort(begin(ukeys), end(ukeys));
    ukeys.erase(unique(begin(ukeys), end(ukeys)), end(ukeys));

    vector<int> uvals(ukeys.size(), 0);

    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(begin(ukeys), end(ukeys), keys[i]) - begin(ukeys);
        uvals[idx] += vals[i];
    }

    printf("%lu\n", ukeys.size());
    for (int i = 0; i < n; ++i) {
        int idx = lower_bound(begin(ukeys), end(ukeys), keys[i]) - begin(ukeys);
        if (used[idx]) continue;
        used[idx] = true;

        printf("%d %d\n", keys[i], uvals[idx]);
    }

    return 0;
}
