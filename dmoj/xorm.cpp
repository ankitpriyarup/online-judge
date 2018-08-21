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

constexpr int MAXN = 100005;
constexpr int LOGN = 32;
int trie[MAXN * LOGN][2];
int trie_len = 1;
int idx[MAXN * LOGN];

void insert(int v, int i) {
    int node = 0;
    for (int j = LOGN - 1; j >= 0; --j) {
        int p = (1 << j);
        bool b = (v & p) > 0;
        if (!trie[node][b]) {
            trie[node][b] = trie_len++;
        }

        node = trie[node][b];
    }

    if (idx[node] == -1)
        idx[node] = i;
}

int query(int v) {
    int node = 0;
    for (int j = LOGN - 1; j >= 0; --j) {
        bool b = (v & (1 << j)) > 0;
        if (!trie[node][b])
            b = !b;
        node = trie[node][b];
    }

    return idx[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    scanf(" %d %d", &n, &q);
    int x;
    memset(idx, -1, sizeof(idx));
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &x);
        insert(x, i);
    }

    int mask = 0;
    while (q-- > 0) {
        scanf(" %d", &x);
        int res = query(x ^ mask);
        printf("%d\n", res);
        mask ^= x;
    }

    return 0;
}
