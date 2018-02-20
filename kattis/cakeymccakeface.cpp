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

constexpr int MAXN = 2505;
int n, m;
ll a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld", a + i);
    }
    for (int i = 0; i < m; ++i) {
        scanf(" %lld", b + i);
    }

    ll ans = 0;
    ll score = 0;
    map<ll, ll> freq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll v = b[j] - a[i];
            ++freq[v];
        }
    }

    for (auto it : freq) {
        // printf("%lld %lld\n", it.first, it.second);
        if (it.first < 0) continue;
        if (it.second > score or (it.second == score and it.first < ans)) {
            ans = it.first;
            score = it.second;
        }
    }

    printf("%lld\n", ans);
    
    return 0;
}
