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

constexpr int MAXN = 50004;
constexpr int MAXK = 1000006;
constexpr int BLOCK = 420;
int n;
int a[2][MAXN];
int freq[2][MAXK];
int ans[MAXN];

void add(int& cur, int ind) {
    int man = a[0][ind];
    int woman = a[1][ind];

    int old_man = min(freq[0][man], freq[1][man]);
    int old_woman = min(freq[0][woman], freq[1][woman]);

    ++freq[0][man];
    ++freq[1][woman];

    int new_man = min(freq[0][man], freq[1][man]);
    int new_woman = min(freq[0][woman], freq[1][woman]);

    cur += new_man - old_man;
    if (man != woman) {
        cur += new_woman - old_woman;
    }
}

void remove(int& cur, int ind) {
    int man = a[0][ind];
    int woman = a[1][ind];

    int old_man = min(freq[0][man], freq[1][man]);
    int old_woman = min(freq[0][woman], freq[1][woman]);

    --freq[0][man];
    --freq[1][woman];

    int new_man = min(freq[0][man], freq[1][man]);
    int new_woman = min(freq[0][woman], freq[1][woman]);

    cur += new_man - old_man;
    if (man != woman) {
        cur += new_woman - old_woman;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, k;
    scanf("%d %d %d", &n, &q, &k);
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[k][i]);
        }
    }

    vector<pair<pii, int> > queries;
    int a, b;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &a, &b);
        queries.push_back({{a, b}, i});
    }

    sort(begin(queries), end(queries), [](const pair<pii, int>& a, const pair<pii, int>& b) {
        int b1 = a.first.first / BLOCK;
        int b2 = b.first.first / BLOCK;

        return b1 < b2 or (b1 == b2 and a.first.second < b.first.second);
    });

    int l = 0;
    int r = 0;
    int cur = 0;
    for (auto& query : queries) {
        tie(a, b) = query.first;
        int ind = query.second;
        while (r <= b) {
            add(cur, r);
            ++r;
        }
        while (b + 1 < r) {
            --r;
            remove(cur, r);
        }
        while (a < l) {
            --l;
            add(cur, l);
        }
        while (l < a) {
            remove(cur, l);
            ++l;
        }
        ans[ind] = cur;
    }

    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
