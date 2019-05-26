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

    int q;
    cin >> q;

    ll b = 0;
    multiset<int> leq, gt;
    ll left_sum = 0LL;
    ll right_sum = 0LL;

    while (q-- > 0) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, bi;
            cin >> a >> bi;
            b += bi;

            if (!gt.empty() and a > *begin(gt)) {
                gt.insert(a);
                right_sum += a;
            } else {
                leq.insert(a);
                left_sum += a;
            }

            while (gt.size() > leq.size()) {
                int x = *begin(gt);
                gt.erase(begin(gt));
                right_sum -= x;
                left_sum += x;
                leq.insert(x);
            }

            while (leq.size() - 1 > gt.size()) {
                int x = *prev(end(leq));
                leq.erase(prev(end(leq)));
                left_sum -= x;

                right_sum += x;
                gt.insert(x);
            }
        } else {
            int x = *prev(end(leq));
            ll cost = b + 1LL * x * leq.size() - left_sum + right_sum - 1LL * x * gt.size();
            cout << x << ' ' << cost << '\n';
        }
    }
    
    return 0;
}
