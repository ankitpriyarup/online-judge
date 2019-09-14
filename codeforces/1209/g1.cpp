#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 200005;
int n, _q;
int a[MAXN], first[MAXN], last[MAXN], weight[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> _q;

    memset(first, -1, sizeof(first));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        if (first[a[i]] == -1)
            first[a[i]] = i;
        last[a[i]] = i;
        ++weight[a[i]];
    }

    using ival = tuple<int, int, int>;
    vector<ival> intervals;
    for (int i = 0; i < MAXN; ++i) {
        if (first[i] != -1) {
            intervals.emplace_back(first[i], last[i], weight[i]);
        }
    }
    sort(all(intervals));

    vector<ival> stk;
    for (auto& iv : intervals) {
        int s, e, w;
        tie(s, e, w) = iv;
        while (!stk.empty() and get<1>(stk.back()) > s) {
            int ns, ne, nw;
            tie(ns, ne, nw) = stk.back();
            stk.pop_back();

            s = min(s, ns);
            e = max(e, ne);
            w = max(w, nw);
        }

        stk.emplace_back(s, e, w);
    }

    int ans = n;
    for (auto& iv : stk) {
        ans -= get<2>(iv);
    }

    cout << ans << '\n';

    return 0;
}
