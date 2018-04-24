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

constexpr int MAXN = 16666;
int n;
int a[MAXN], b[MAXN];

int get_last(const set<int>& s) {
    if (s.empty())
        return -1;
    return *prev(end(s));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    vector<pii> starts(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &a[i], &b[i]);
        starts[i] = {a[i], i};
    }

    sort(begin(starts), end(starts));
    set<int> ends;

    int ans = 0;
    for (pii& p : starts) {
        int x = p.first;
        int idx = p.second;

        // printf("Processing interval %d [%d, %d]\n", idx, a[idx], b[idx]);

        while (!ends.empty() and x > *begin(ends)) {
            // printf("Erasing end %d\n", *begin(ends));
            ends.erase(begin(ends));
        }

        if (b[idx] < get_last(ends)) {
            // printf("Interval fully contained in something else\n");
            ++ans;
            continue;
        }

        ends.insert(b[idx]);
        // printf("Inserting end %d\n", b[idx]);
    }
    printf("%d\n", ans);

    return 0;
}
