#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);

    vector<pii> events;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);

        events.push_back({a[i], 1});
        events.push_back({a[i] + 1000, -1});
    }

    sort(begin(events), end(events));

    int cur = 0;
    int ans = 0;
    for (pii event : events) {
        cur += event.second;
        ans = max(cur, ans);
    }

    int machines = (ans + k - 1) / k;
    printf("%d\n", machines);

    return 0;
}
