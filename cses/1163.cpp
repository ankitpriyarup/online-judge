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

    int l, q;
    cin >> l >> q;
    multiset<int> pos, gaps;
    pos.insert(0);
    pos.insert(l);
    gaps.insert(l);

    while (q-- > 0) {
        int x;
        cin >> x;
        auto it = pos.upper_bound(x);
        int a = *prev(it);
        int b = *it;
        gaps.erase(gaps.find(b - a));
        gaps.insert(b - x);
        gaps.insert(x - a);
        pos.insert(x);

        cout << *prev(end(gaps)) << ' ';
    }


    return 0;
}
