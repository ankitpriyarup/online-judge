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

ll C = 123891739;

ll make_hash(const string& s) {
    ll ha = 0LL;
    for (int i = 0; i < s.size(); ++i) {
        ha = ha * C + s[i];
    }

    return ha;
}

constexpr int MAXN = 100005;
int n, m;
ll seq[MAXN];
int freq[MAXN];
map<ll, int> used_ind;

int cur_count = 0;

void add(int i) {
    if (used_ind.find(seq[i]) == end(used_ind))
        return;

    int v = used_ind[seq[i]];
    if (!freq[v]) {
        ++cur_count;
    }
    ++freq[v];
}

void rem(int i) {
    if (used_ind.find(seq[i]) == end(used_ind))
        return;

    int v = used_ind[seq[i]];
    assert(freq[v] > 0);
    if (freq[v] == 1) {
        --cur_count;
    }
    --freq[v];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        seq[i] = make_hash(s);
    }

    for (int i = 0; i < m; ++i) {
        cin >> s;
        ll v = make_hash(s);
        used_ind[v] = i;
    }

    int j = 0;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        if (i == j) {
            add(i);
            ++j;
        }

        while (cur_count < m and j < n) {
            add(j);
            ++j;
        }

        if (cur_count == m) {
            // printf("Range %d to %d is good\n", i, j);
            ans += n - j + 1;
        }

        rem(i);
    }

    cout << ans << '\n';

    return 0;
}
