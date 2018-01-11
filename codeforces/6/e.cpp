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
int n, k;
int a[MAXN];

int span(const multiset<int>& m) {
    assert(m.size() > 1);

    int x = *m.begin();
    int y = *prev(m.end());
    return y - x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    multiset<int> m;
    for (int i = 1; i <= n; ++i) 
        scanf("%d", a + i);

    int sz = 1;
    vector<pii> res;

    int j = 1;
    for (int i = 1; i <= n; ++i) {
        m.insert(a[i]);
        while (j < i and span(m) > k) {
            auto it = m.find(a[j]);
            m.erase(it);
            ++j;
        }

        if (m.size() > sz) {
            sz = m.size();
            res.clear();
        }
        if (m.size() == sz) {
            res.push_back({j, i});
        }
    }

    printf("%d %d\n", sz, (int)res.size());
    for (const pii& r : res) {
        printf("%d %d\n", r.first, r.second);
    }

    return 0;
}
