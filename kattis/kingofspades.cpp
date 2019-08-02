#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MOD = 1e9 + 23;
int value[255], hashes[255];

vector<string> read(int n) {
    vector<string> res(n);
    for (int i = 0; i < n; ++i) {
        cin >> res[i];
    }

    return res;
}

inline void update(int& hash, int v) {
    hash += v;
    if (hash < 0)
        hash += MOD;
    else if (hash >= MOD)
        hash -= MOD;
}

inline void add(const string& card, int& bad, int& score, int& hash1, int& hash2) {
    if (card == "KS")
        ++bad;
    score += value[card[0]];

    update(hash1, hashes[card[0]]);
    update(hash2, hashes[card[1]]);
}

inline void rem(const string& card, int& bad, int& score, int& hash1, int& hash2) {
    if (card == "KS")
        --bad;
    score -= value[card[0]];
    update(hash1, MOD - hashes[card[0]]);
    update(hash2, MOD - hashes[card[1]]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < 255; ++i) {
        hashes[i] = uniform_int_distribution<int>(MOD / 2, MOD - 1)(rng);
    }

    for (char c = '2'; c <= '9'; ++c) {
        value[c] = c - '0';
    }
    value['T'] = 10;
    value['J'] = 10;
    value['Q'] = 10;
    value['K'] = 10;
    value['A'] = 1;

    int n, m;
    cin >> n >> m;
    vector<string> a = read(n);
    vector<string> b = read(m);

    int max_window = min(100, min(n, m));
    int ans = 0;
    for (int len = 1; len <= max_window; ++len) {
        int bad = 0;
        int score = 0;
        int hash1 = 0;
        int hash2 = 0;
        for (int i = 0; i < len; ++i) {
            add(a[i], bad, score, hash1, hash2);
        }

        set<tuple<int, int, int>> seen;
        seen.emplace(score, hash1, hash2);

        // add to set
        for (int i = len; i < n; ++i) {
            // remove i - len from window
            rem(a[i - len], bad, score, hash1, hash2);

            // add i to window
            add(a[i], bad, score, hash1, hash2);

            // add to set
            if (bad == 0) {
                seen.emplace(score, hash1, hash2);
            }
        }

        // make a new state
        bad = 0;
        score = 0;
        hash1 = 0;
        hash2 = 0;
        for (int i = 0; i < len; ++i) {
            add(b[i], bad, score, hash1, hash2);
        }

        // check if in set
        if (bad == 0 and seen.count({score, hash1, hash2})) {
            ans = max(ans, score);
        }
        for (int i = len; i < m; ++i) {
            // remove i - len from window
            rem(b[i - len], bad, score, hash1, hash2);

            // add i to window
            add(b[i], bad, score, hash1, hash2);

            // check set
            if (bad == 0 and seen.count({score, hash1, hash2})) {
                ans = max(ans, score);
            }
        }
    }

    ans *= 2;
    cout << ans << '\n';
    return 0;
}
