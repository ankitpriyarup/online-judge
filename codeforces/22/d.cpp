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

    int n;
    cin >> n;
    constexpr int MAXV = 10004;
    vector<vi> ends(MAXV + MAXV + 1);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        if (l > r)
            swap(l, r);
        l += MAXV;
        r += MAXV;

        ends[r].push_back(l);
    }

    vi nails;

    for (int i = 0; i < ends.size(); ++i) {
        bool all_covered = true;
        for (int l : ends[i]) {
            all_covered &= (!nails.empty() and nails.back() >= l);
        }

        if (!all_covered) {
            nails.push_back(i);
        }
    }

    cout << nails.size() << '\n';
    for (int x : nails) {
        cout << (x - MAXV) << ' ';
    }
    
    return 0;
}
