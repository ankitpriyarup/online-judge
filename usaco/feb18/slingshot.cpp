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
using trip = tuple<ll, ll, ll>;

constexpr ll INF = 1e17;

void compress(vector<ll>& v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

int get_idx(const vector<ll>& v, ll x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}

// Taken from saketh-are
template<typename T>
struct seg_tree {
    int S;

    T zero;
    vector<T> value;

    seg_tree<T>(int _S, T _zero = INF) {
        S = _S, zero = _zero;
        value.resize(2 * S + 1, zero);
    }

    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);

        for (int i = S - 1; i > 0; i--) 
            value[i] = min(value[2 * i], value[2 * i + 1]);
    }

    void upd(int i, T v, bool force=false) {
        i += S;
        if (!force and (v + value[i]) == value[i])
            return;

        value[i] = v;
        while(i>1){
            i /= 2;
            value[i] = min(value[2*i], value[2*i+1]);
        }
    }

    T query(int i, int j) {
        T res_left = zero, res_right = zero;
        for(i += S, j += S; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = min(res_left, value[i++]);
            if((j&1) == 0) res_right = min(value[j--], res_right);
        }

        return min(res_left, res_right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("slingshot.in", "r", stdin);
    freopen("slingshot.out", "w", stdout);

    int n, m;
    scanf("%d %d", &n, &m);
    ll x, y, t;
    vector<trip> slingshots;
    vector<ll> all_x, all_y;
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &x, &y, &t);
        slingshots.emplace_back(x, y, t);
        all_x.push_back(x);
        all_y.push_back(y);
    }

    sort(begin(slingshots), end(slingshots));

    ll a, b;
    vector<trip> manures;
    for (int i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        manures.emplace_back(a, b, i);
        all_x.push_back(a);
        all_y.push_back(b);
    }

    sort(begin(manures), end(manures));

    compress(all_x);
    compress(all_y);

    vector<ll> ans(m, INF);
    seg_tree<ll> before_below(all_y.size());
    seg_tree<ll> before_above(all_y.size());
    seg_tree<ll> after_below(all_y.size());
    seg_tree<ll> after_above(all_y.size());

    vector<ll> above_leaves(all_y.size(), INF);
    vector<ll> below_leaves(all_y.size(), INF);

    for (int i = 0; i < n; ++i) {
        tie(x, y, t) = slingshots[i];
        int cx = get_idx(all_x, x);
        int cy = get_idx(all_y, y);

        above_leaves[cy] = min(above_leaves[cy], (0LL + x + y + t));
        below_leaves[cy] = min(below_leaves[cy], (0LL + x - y + t));
    }

    after_above.set_leaves(above_leaves);
    after_below.set_leaves(below_leaves);

    int ptr = 0;
    ll idx;
    for (int i = 0; i < m; ++i) {
        tie(a, b, idx) = manures[i];
        while (ptr < n and get<0>(slingshots[ptr]) < a) {
            tie(x, y, t) = slingshots[ptr];
            // printf("Moving slingshot (%d, %d, %d) behind\n", x, y, t);
            int cy = get_idx(all_y, y);

            before_above.upd(cy, 0LL - x + t + y);
            before_below.upd(cy, 0LL - x + t - y);

            after_above.upd(cy, INF, true);
            after_below.upd(cy, INF, true);

            ++ptr;
        }
        
        ll ret = abs(b - a);

        int cb = get_idx(all_y, b);
        ret = min(ret, before_above.query(cb, all_y.size() - 1) + a - b);
        ret = min(ret, before_below.query(0, cb) + a + b);
        ret = min(ret, after_above.query(cb, all_y.size() - 1) - a - b);
        ret = min(ret, after_below.query(0, cb) - a + b);

        ans[idx] = ret;
    }

    --ptr;
    for (int i = m - 1; i >= 0; --i) {
        tie(a, b, idx) = manures[i];
        while (ptr >= 0 and get<0>(slingshots[ptr]) > a) {
            tie(x, y, t) = slingshots[ptr];
            int cy = get_idx(all_y, y);

            after_above.upd(cy, 0LL + x + t + y);
            after_below.upd(cy, 0LL + x + t - y);

            before_above.upd(cy, INF, true);
            before_below.upd(cy, INF, true);

            --ptr;
        }

        ll ret = ans[idx];
        int cb = get_idx(all_y, b);
        ret = min(ret, before_above.query(cb, all_y.size() - 1) + a - b);
        ret = min(ret, before_below.query(0, cb) + a + b);
        ret = min(ret, after_above.query(cb, all_y.size() - 1) - a - b);
        ret = min(ret, after_below.query(0, cb) - a + b);

        ans[idx] = ret;
    }

    for (int i = 0; i < m; ++i) {
        printf("%lld\n", ans[i]);
    }

    return 0;
}
