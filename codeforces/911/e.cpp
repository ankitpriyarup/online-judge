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

constexpr int MAXN = 200005;
constexpr int INF = 1e9;
int n, k;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    vector<int> stk;
    int want = 1;
    for (int i = 0; i < k; ++i) {
        scanf("%d", a + i);
        stk.push_back(a[i]);
        while (!stk.empty() and stk.back() == want) {
            stk.pop_back();
            ++want;
        }
    }

    vector<int> sorted(begin(stk), end(stk));
    sort(begin(sorted), end(sorted));
    reverse(begin(sorted), end(sorted));

    if (sorted != stk) {
        printf("%d\n", -1);
        return 0;
    }

    for (int i = k; i < n; ++i) {
        while (!stk.empty() and stk.back() == want) {
            stk.pop_back();
            ++want;
        }

        a[i] = stk.empty() ? n : stk.back() - 1;
        stk.push_back(a[i]);
    }

    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');

    return 0;
}
