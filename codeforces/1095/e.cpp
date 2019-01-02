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

struct node {
    int sum, pref;
    node(): sum(0), pref(0) {}
    node(int s, int p): sum(s), pref(min(0, p)) {}

    node operator+(const node& o) const {
        return node(sum + o.sum, min(0, min(pref, sum + o.pref)));
    }

    bool valid() const {
        return sum == 0 and pref == 0;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n <= 1) {
        cout << 0;
        return 0;
    }
    vector<node> pref(n), suff(n);
    // each block has: min prefix and sum
    // block is valid if min prefix == 0 and sum == 0
    //
    const node OPEN(1, 0);
    const node CLOSE(-1, -1);

    pref[0] = s[0] == '(' ? OPEN : CLOSE;
    for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + (s[i] == '(' ? OPEN : CLOSE);
    }

    suff[n - 1] = s[n - 1] == '(' ? OPEN : CLOSE;
    for (int i = n - 2; i >= 0; --i) {
        suff[i] = (s[i] == '(' ? OPEN : CLOSE) + suff[i + 1];
    }

    int ans = 0;
    if (s[0] == ')' and (OPEN + suff[1]).valid()) {
        ++ans;
    }
    if (s[n - 1] == '(' and (pref[n - 2] + CLOSE).valid()) {
        ++ans;
    }

    for (int i = 1; i < n - 1; ++i) {
        node here = s[i] == '(' ? CLOSE : OPEN;
        ans += (pref[i - 1] + here + suff[i + 1]).valid();
    }

    cout << ans << '\n';

    return 0;
}
