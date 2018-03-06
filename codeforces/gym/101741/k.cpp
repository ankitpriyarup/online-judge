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
using query = tuple<int, int, string>;

using H = unsigned long long;

struct HashInterval {
    const static H C1 = 123891739;
    const static H C2 = 831579821;
    const static H M1 = 1000000007;
    const static H M2 = 1000000009;
    vector<H> ha1, ha2, pw1, pw2;
    HashInterval(const string& s) : ha1(s.size() + 1), ha2(s.size() + 1), pw1(ha1), pw2(ha2) {
        pw1[0] = 1;
        pw2[0] = 1;
        for (int i = 0; i < s.size(); ++i) {
            ha1[i + 1] = (ha1[i] * C1 + s[i]) % M1;
            pw1[i + 1] = (pw1[i] * C1) % M1;

            ha2[i + 1] = (ha2[i] * C2 + s[i]) % M2;
            pw2[i + 1] = (pw2[i] * C2) % M2;
        }
    }

    // [a, b)
    pair<H, H> hashInterval(int a, int b) {
        return make_pair((ha1[b] - (ha1[a] * pw1[b - a]) % M1 + M1) % M1, (ha2[b] - (ha2[a] * pw2[b - a]) % M2 + M2) % M2 );
    }
};

pair<H, H> hashString(string& s) {
    H h1 = 0;
    H h2 = 0;
    for (char c : s) h1 = (h1 * HashInterval::C1 + c) % HashInterval::M1;
    for (char c : s) h2 = (h2 * HashInterval::C2 + c) % HashInterval::M2;

    return make_pair(h1, h2);
}

constexpr int MAXN = 100005;
int n, q;
query queries[MAXN];
int uf[MAXN];
int last[MAXN];
int ans[MAXN];
int ret[MAXN];

int find(int x) {
    return uf[x] = uf[x] == x ? x : find(uf[x]);
}

bool merge(int x, int y) {
    int xr = find(x);
    int yr = find(y);
    if (xr == yr)
        return false;
    uf[xr] = yr;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> n >> q;
    cin >> s;

    string qs;
    for (int i = 0; i < q; ++i) {
        cin >> qs;
        queries[i] = make_tuple(qs.size(), i, qs);
        uf[i] = i;
    }

    memset(last, 0, sizeof(last));
    memset(ans, 0, sizeof(ans));

    HashInterval hashInterval(s);

    sort(queries, queries + q);
    int i = 0;
    while (i < q) {
        int len = get<0>(queries[i]);
        int j = i;
        map<pair<H, H>, int> by_hash;

        while (j < q and get<0>(queries[j]) == len) {
            pair<H, H> curhash = hashString(get<2>(queries[j]));
            if (by_hash.find(curhash) != end(by_hash)) {
                merge(by_hash[curhash], j);
                by_hash[curhash] = find(j);
            } else {
                by_hash[curhash] = j;
            }
            ++j;
        }

        // process this block
        for (int i = 0; i + len <= n; ++i) {
            pair<H, H> curhash = hashInterval.hashInterval(i, i + len);
            auto it = by_hash.find(curhash);
            if (it == by_hash.end())
                continue;

            int idx = it->second;
            if (last[idx] > i) {
                continue;
            }

            ++ans[idx];
            last[idx] = i + len;
        }

        i = j;
    }

    for (int i = 0; i < q; ++i) {
        ret[get<1>(queries[i])] = ans[find(i)];
    }

    for (int i = 0; i < q; ++i) {
        printf("%d\n", ret[i]);
    }

    return 0;
}
