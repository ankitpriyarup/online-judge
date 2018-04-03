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
using vi = vector<int>;

constexpr int MAXN = 1e6 + 666;
constexpr int MOD = 1e9 + 7;

int fact[MAXN];

int modpow(int b, int e) {
    int res = 1;
    int cur = b;
    for (int p = 1; p <= e; p <<= 1) {
        if (p & e) {
            res = (1LL * res * cur) % MOD;
        }

        cur = (1LL * cur * cur) % MOD;
    }

    return res;
}

int inv(int x) {
    return modpow(x, MOD - 2);
}

void gen_fact(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (1LL * fact[i - 1] * i) % MOD;
    }
}

int trie[MAXN][26];
int word_end[MAXN];
int nnode = 1;

void insert(const string& s, int str_ind) {
    int node = 0;
    for (int i = 0; i < s.size(); ++i) {
        int idx = s[i] - 'a';
        if (trie[node][idx] == -1) {
            trie[node][idx] = nnode++;
        }

        node = trie[node][idx];
    }

    word_end[node] = str_ind;
}

pii query(const string& s, int start) {
    int node = 0;
    for (int i = start; i < s.size(); ++i) {
        int idx = s[i] - 'a';
        assert(trie[node][idx] != -1);

        node = trie[node][idx];
        if (word_end[node] != -1) {
            return {word_end[node], i + 1};
        }
    }

    return {-1, s.size() + 2};
}

int f_tree[MAXN];

int sum(const int& a, const int& b) {
    int c = a + b;
    if (c >= MOD) {
        c -= MOD;
    }

    return c;
}

int prod(const int& a, const int& b) {
    return (1LL * a * b) % MOD;
}
int query(int i) {
    int ans = 0;
    for (int x = i + 1; x; x -= (x & -x)) {
        ans += f_tree[x];
    }

    return ans;
}


void update(int i, int v) {
    for (int x = i + 1; x < MAXN; x += (x & -x)) {
        f_tree[x] += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<string> strings(n);
    for (int i = 0; i < n; ++i) {
        cin >> strings[i];
    }
    sort(begin(strings), end(strings));

    memset(trie, -1, sizeof(trie));
    memset(word_end, -1, sizeof(word_end));
    for (int i = 0; i < n; ++i) {
        insert(strings[i], i);
        update(i, 1);
    }

    string test_string;
    cin >> test_string;

    gen_fact(n);
    int num_remaining = n;
    int ans = 1;
    int skip = (1LL * fact[n - 1] * inv(fact[n - k])) % MOD;

    for (int i = 0; i < test_string.size();) {
        pii res = query(test_string, i);
        int idx = res.first;

        assert(idx != -1);
        int num_smaller = query(idx - 1);

        ans = (ans + (1LL * skip * num_smaller) % MOD) % MOD;
        update(idx, -1);
        skip = (1LL * skip * inv(num_remaining - 1)) % MOD;
        --num_remaining;

        i = res.second;
        assert(i <= test_string.size());
    }

    cout << ans << '\n';

    return 0;
}
