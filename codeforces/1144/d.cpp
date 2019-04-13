#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    constexpr int MAXN = 200005;
    int n;
    cin >> n;

    vi a(n);
    vi freq(MAXN, 0);
    int best_freq = -1;
    int goal = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (++freq[a[i]] > best_freq) {
            best_freq = freq[a[i]];
            goal = a[i];
        }
    }

    int first = 0;
    while (a[first] != goal) ++first;

    vector<tuple<int, int, int>> ans;

    for (int i = first - 1; i >= 0; --i) {
        assert(a[i + 1] == goal);
        if (a[i] == goal) continue;

        int op = a[i] > a[i + 1] ? 2 : 1;
        ans.emplace_back(op, i, i + 1);
        a[i] = goal;
    }

    for (int i = first + 1; i < n; ++i) {
        assert(a[i - 1] == goal);
        if (a[i] == goal) continue;

        int op = a[i] > a[i - 1] ? 2 : 1;
        ans.emplace_back(op, i, i - 1);
        a[i] = goal;
    }

    cout << ans.size() << '\n';
    for (auto& t : ans) {
        int x, y, z;
        tie(x, y, z) = t;
        ++y; ++z;
        cout << x << ' ' << y << ' ' << z << '\n';
    }
    
    return 0;
}
