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

    int T;
    cin >> T;
    while (T-- > 0) {
        int d, x, s;
        cin >> d >> x >> s;

        int pl = 1e9 + 7;
        int ps = 1e9 + 7;

        ll lem_ans = 0LL;
        ll sug_ans = 0LL;

        int extra_sugar = 0;

        for (int i = 0; i < d; ++i) {
            int c, npl, nps;
            cin >> c >> npl >> nps;
            pl = min(pl, npl);
            ps = min(ps, nps);

            int lem = c * x;
            lem_ans += lem * pl;

            int needed_sugar = c * s;
            int packs = (max(0, needed_sugar - extra_sugar) + 79) / 80;
            sug_ans += packs * ps;
            extra_sugar += 80 * packs;
            extra_sugar -= needed_sugar;
        }

        cout << (lem_ans + sug_ans) << '\n';
    }
    
    return 0;
}
