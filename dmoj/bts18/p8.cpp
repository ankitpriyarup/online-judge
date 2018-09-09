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

constexpr int MAXD = 5003;
constexpr int SQK = 10000000;
using bs = bitset<MAXD>;

bs gen_primes(ll k) {
    bs res(k);
    res.set();

    bitset<SQK> sieve;
    vector<ll> small_primes = {2};
    for (int i = 3LL; i <= SQK; i += 2) {
        if (!sieve[i]) {
            small_primes.push_back(i);
            for (ll j = 1LL * i * i; j <= SQK; j += 2LL * i) {
                sieve[j] = true;
            }
        }
    }

    for (ll p : small_primes) {
        ll m = (k / p) * p;
        while (m < k or m <= p)
            m += p;
        for (ll x = m; x <= k + 5000; x += p) {
            res.reset(x - k);
        }
    }

    return res;
}

struct node {
    int l, r;
    int lazy;
    bs b;

    node *left, *right;

    node(): l(0), r(0), lazy(0), left(nullptr), right(nullptr) {}

    node(int l, int r, bs b, node* left = nullptr, node* right = nullptr):
        l(l), r(r), lazy(0), b(b), left(left), right(right) {}

    bs shift(const bs& b, int x) const {
        if (x >= 0)
            return b << x;
        else
            return b >> (-x);
    }

    void push() {
        if (lazy == 0)
            return;
        
        b = shift(b, lazy);

        left->lazy += lazy;
        right->lazy += lazy;

        lazy = 0;
    }

    void pull() {
        b = shift(left->b, left->lazy) | shift(right->b, right->lazy);
    }

    bs query(int ql, int qr) {
        if (r < ql or qr < l) {
            bs empty;
            return empty;
        }
        if (ql <= l and r <= qr) {
            return shift(b, lazy);
        }

        push();
        auto res = left->query(ql, qr) | right->query(ql, qr);
        pull();

        return res;
    }

    void update(int ql, int qr, int v) {
        if (r < ql or qr < l) {
            return;
        }

        if (ql <= l and r <= qr) {
            lazy += v;
            return;
        }

        push();
        left->update(ql, qr, v);
        right->update(ql, qr, v);
        pull();
    }
};

node* build_tree(const vector<ll>& a, int l, int r) {
    if (l == r) {
        bs b;
        b.set(a[l]);
        return new node(l, r, b);
    } else {
        int mid = (l + r) >> 1;
        node* left = build_tree(a, l, mid);
        node* right = build_tree(a, mid + 1, r);
        return new node(l, r, left->b | right->b, left, right);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // f(x) = x if x is prime, -1 otherwise
    // first find all primes between K and K + 5 * 10^3
    // then make a segment tree, each node has a bitset of primes
    int n, q;
    ll k;
    cin >> n >> q >> k;
    bs prime = gen_primes(k);
    vector<int> idx;
    for (int i = 5000; i >= 0; --i) {
        if (prime[i])
            idx.push_back(i);
    }

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= k;
    }

    node* root = build_tree(a, 0, n - 1);
    int op, l, r, v;
    while (q-- > 0) {
        cin >> op >> l >> r;
        --l; --r;
        if (op == 1) {
            bs q = prime & root->query(l, r);
            if (q.none()) {
                cout << -1 << '\n';
            } else {
                for (int x : idx) {
                    if (q[x]) {
                        cout << (k + x) << '\n';
                        break;
                    }
                }
            }
        } else {
            cin >> v;
            root->update(l, r, v);
        }
    }

    return 0;
}
