#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

constexpr int MAXN  = 50005;
constexpr int MAXL  = 100005;
constexpr int NHASH = 3;
constexpr int MOD[NHASH] = {1000000007, 1000000009, 1000000021};
constexpr int SIGMA = 27;
constexpr int BLOOM_SIZE = MOD[NHASH - 1];

int n;

string s[MAXN];
char buf[MAXL];

int powers[NHASH][MAXL];
int cur_hash[NHASH];
bitset<BLOOM_SIZE> bloom[NHASH];

inline int sum(const int& a, const int& b, const int& m) {
    int c = a + b;
    if (c < 0) {
        c += m;
    } else if (c >= m) {
        c -= m;
    }

    return c;
}

inline int prod(const int& a, const int& b, const int& m) {
    return (((1LL * a * b) % m) + m) % m;
}

inline void reset_hash(int len) {
    memset(cur_hash, 0, sizeof(cur_hash));

    for (int i = 0; i < NHASH; ++i) {
        powers[i][0] = 1;
        for (int j = 1; j <= len; ++j) {
            powers[i][j] = prod(powers[i][j - 1], SIGMA, MOD[i]);
        }
    }
}

inline void add(const char& c) {
    for (int i = 0; i < NHASH; ++i) {
        cur_hash[i] = prod(cur_hash[i], SIGMA, MOD[i]);
        cur_hash[i] = sum(cur_hash[i], (c - 'a' + 1), MOD[i]);
    }
}

inline void remove(const int& p, const char& c) {
    for (int i = 0; i < NHASH; ++i) {
        cur_hash[i] = sum(cur_hash[i], -powers[i][p] * (c - 'a' + 1), MOD[i]);
    }
}

inline void bloom_reset() {
    for (int i = 0; i < NHASH; ++i) {
        bloom[i].reset();
    }
}

inline void bloom_insert() {
    for (int i = 0; i < NHASH; ++i) {
        bloom[i].set(cur_hash[i]);
    }
}

inline bool bloom_query() {
    bool ans = true;
    for (int i = 0; i < NHASH; ++i) {
        ans &= bloom[i][cur_hash[i]];
    }

    return ans;
}

bool search(const int& a, const int& b, const int& len) {
    reset_hash(len);
    for (int i = 0; i < len; ++i) {
        add(s[a][i]);
    }

    bloom_reset();
    bloom_insert();
    for (int i = len; i < s[a].size(); ++i) {
        remove(len - 1, s[a][i - len]);
        add(s[a][i]);
        bloom_insert();
    }

    reset_hash(len);
    for (int i = 0; i < len; ++i) {
        add(s[b][i]);
    }

    if (bloom_query())
        return true;
    for (int i = len; i < s[b].size(); ++i) {
        remove(len - 1, s[b][i - len]);
        add(s[b][i]);
        if (bloom_query()) return true;
    }

    return false;
}

int solve(const int& a, const int& b) {
    // longest substring of s[a] that occurs in s[b]
    int lo = 0;
    int hi = min(s[a].size(), s[b].size()) + 1;

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (search(a, b, mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return lo;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);

    // O(n * b)
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        s[i] = string(buf);
    }

    int a, b;
    while (q-- > 0) {
        scanf("%d %d", &a, &b);
        int ans = solve(a, b);
        printf("%d\n", ans);
    }

    return 0;
}
