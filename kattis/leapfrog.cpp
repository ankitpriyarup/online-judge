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

constexpr int MAX_N = 45;

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int n;
ll offset[MAX_N];
ll mo[MAX_N];

map<ll, map<ll, vector<int> > > by_mod;

ll mod(ll a, ll b) {
    return ((a % b) + b) % b;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }

    return a;
}

pair<ll, ll> chinese_remainder_theorem(ll m1, ll r1, ll m2, ll r2) {
    ll s, t;
    ll g = extended_euclid(m1, m2, s, t);
    if (r1 % g != r2 % g) return { 0, -1 };
    return { mod(s * r2 * m1 + t * r1 * m2, m1 * m2) / g, m1 * m2 / g };
}

pair<ll, ll> chinese_remainder_theorem(const vector<ll> &m, const vector<ll> &r) {
    pair<ll, ll> ret = { r[0], m[0] };
    for (int i = 1; i < m.size(); i++) {
        ret = chinese_remainder_theorem(ret.second, ret.first, m[i], r[i]);
        if (ret.second == -1) break;
    }

    return ret;
}

vector<ll> all_mods;
vector<ll> m, r;
int total = 0;
ll max_offset;

int best_total = 0;
ll best_pos;

void dfs(int pos) {
    if (pos == all_mods.size()) {
        auto res = chinese_remainder_theorem(m, r);
        ll rem = res.first;
        ll big_mod = res.second;

        ll k = (max_offset - rem + big_mod - 1) / big_mod;
        ll real_pos = k * big_mod + rem;

        if (total > best_total) {
            best_total = total;
            best_pos = real_pos;
        } else if (total == best_total) {
            best_pos = min(real_pos, best_pos);
        }
    }

    m.push_back(all_mods[pos]);

    for (auto rem : by_mod[all_mods[pos]]) {
        r.push_back(rem.first);

        total += rem.second.size();
        ll temp = max_offset;

        for (int index : rem.second) {
            max_offset = max(max_offset, offset[index]);
        }

        dfs(pos + 1);

        total -= rem.second.size();
        max_offset = temp;
        r.pop_back();
    }

    m.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %lld %lld", &offset[i], &mo[i]);
        by_mod[mo[i]][offset[i] % mo[i]].push_back(i);
    }

    for (auto it : by_mod) {
        all_mods.push_back(it.first);
    }

    dfs(0);

    printf("%lld %d\n", best_pos, best_total);

    return 0;
}
