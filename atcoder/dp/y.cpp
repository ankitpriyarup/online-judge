#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 7;

int sum(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

int prod(int a, int b) {
    return 1LL * a * b % MOD;
}

int modpow(int b, int e) {
    if (e == 0) return 1;
    if (e & 1) return prod(b, modpow(b, e ^ 1));
    return modpow(prod(b, b), e >> 1);
}

inline int inv(int x) {
    return modpow(x, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h, w, n;
    cin >> h >> w >> n;

    int max_f = h + w + 1;
    vi fact(max_f), tcaf(max_f);
    fact[0] = fact[1] = 1;
    for (int i = 2; i < max_f; ++i) {
        fact[i] = prod(fact[i - 1], i);
    }

    tcaf[max_f - 1] = inv(fact[max_f - 1]);
    for (int i = max_f - 2; i >= 0; --i) {
        tcaf[i] = prod(tcaf[i + 1], i + 1);
    }

    vector<pii> blocks;
    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        blocks.emplace_back(r, c);
    }
    blocks.emplace_back(h - 1, w - 1);
    ++n;

    sort(all(blocks));

    // number of paths from 0, 0 to (r, c) with no blocks is
    // (r + c) choose r
    // precompute factorials and such
    //
    // now with blocks
    // let dp[i] = # of ways to get to block i where i is the first block encountered
    // then its (r + c) choose r - (dx + dy) choose dx far all other previous blocks
    vi dp(n);
    for (int i = 0; i < n; ++i) {
        int r, c;
        tie(r, c) = blocks[i];
        dp[i] = prod(fact[r + c], prod(tcaf[r], tcaf[c]));
        for (int j = 0; j < n; ++j) {
            if (j == i) continue;
            int dr = r - blocks[j].first;
            int dc = c - blocks[j].second;
            if (dr >= 0 and dc >= 0) {
                int cut = prod(fact[dr + dc], prod(tcaf[dr], tcaf[dc]));
                cut = prod(dp[j], cut);
                dp[i] = sum(dp[i], MOD - cut);
            }
        }
    }

    cout << dp.back() << '\n';

    return 0;
}
