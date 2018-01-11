#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 100005;
int n;
char s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    scanf("%s", s);

    int prefix = 0;
    map<int, int> m;
    m[0] = -1;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        prefix += (s[i] == '0' ? -1 : 1);
        if (m.find(prefix) != m.end()) {
            ans = max(ans, i - m[prefix]);
        } else {
            m[prefix] = i;
        }
    }

    printf("%d\n", ans);
    return 0;
}
