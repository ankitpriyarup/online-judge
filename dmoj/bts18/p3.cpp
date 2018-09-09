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

    ll n, x;
    cin >> n >> x;
    ll v;
    priority_queue<ll> pq;
    while (n-- > 0) {
        cin >> v;
        pq.push(v);
    }

    ll ans = 0LL;
    while (x-- > 0) {
        ll v = pq.top();
        pq.pop();
        ans += max(v, 0LL);
        pq.push(v - 1);
    }

    cout << ans << '\n';
    
    return 0;
}
