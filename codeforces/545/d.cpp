#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

constexpr int MAXN = 100005;
int n;
int a[MAXN];

int main() {
    scanf("%d", &n);
    multiset<ll> s;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        s.insert(a[i]);
    }

    ll wait = 0LL;
    int ans = 0LL;
    while (!s.empty()) {
        auto it = s.lower_bound(wait);
        if (it == end(s))
            break;

        ll x = *it;
        s.erase(it);
        ++ans;
        wait += x;
    }

    printf("%d\n", ans);
    return 0;
}
