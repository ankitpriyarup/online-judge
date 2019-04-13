#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

// lengths, prev
tuple<vi, vi, int> lis(const vi& a) {
    int n = a.size();

    vi dp(n, 1);
    vi previ(n, -1);
    vector<pii> lis = {{a[0], 0}};
    for (int i = 1; i < n; ++i) {
        if (a[i] > lis.back().first) {
            dp[i] = lis.size();
            previ[i] = lis.back().second;
            lis.emplace_back(a[i], i);
        } else {
            int idx = lower_bound(all(lis), make_pair(a[i], -1)) - begin(lis);
            dp[i] = dp[lis[idx].second];
            previ[i] = previ[lis[idx].second];
            lis[idx] = {a[i], i};
        }
    }

    return {dp, previ, lis.back().second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int k = 0; k < 2; ++k) {
        vi dp, previ;
        int idx;
        tie(dp, previ, idx) = lis(a);
        vi in_lis(n, 0);
        while (idx != -1) {
            in_lis[idx] = true;
            idx = previ[idx];
        }

        vi rem;
        for (int i = 0; i < n; ++i) {
            if (!in_lis[i]) {
                rem.push_back(a[i]);
            }
        }

        bool dec = true;
        for (int i = 1; i < rem.size(); ++i) {
            dec &= rem[i] < rem[i - 1];
        }

        if (dec) {
            cout << "YES\n";
            for (int i = 0; i < n; ++i) {
                cout << (1 ^ k ^ in_lis[i]) << ' ';
            }
            cout << '\n';
            return 0;
        }

        for (int i = 0; i < n; ++i) {
            a[i] = -a[i];
        }
    }

    cout << "NO\n";
    return 0;
}
