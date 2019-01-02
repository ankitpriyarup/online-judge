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

    int n, t, k;
    cin >> n >> t >> k;
    vector<int> freq(t), a(t), b(t);
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        --x;
        freq[x]++;
    }

    vector<ll> v;
    ll ans = 0LL;
    for (int i = 0; i < t; ++i) {
        cin >> a[i] >> b[i];
        ll buy = 1LL * (2 - freq[i]) * a[i];
        ll sell = 1LL * freq[i] * b[i];
        ans += sell;
        v.push_back(-buy - sell);
    }
    sort(begin(v), end(v));
    for (int i = 0; i < k; ++i) {
        ans += v.back();
        v.pop_back();
    }

    cout << ans << '\n';

    return 0;
}
