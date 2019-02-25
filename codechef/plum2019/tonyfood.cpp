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
    vi a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 3 != 0) {
        cout << "No\n";
        return 0;
    }

    int goal = sum / 3;
    bool poss = false;
    for (int mask = 1; !poss and mask < (1 << n); ++mask) {
        int mask_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                mask_sum += a[i];
            }
        }
        if (mask_sum != 2 * goal) {
            continue;
        }
        for (int ss = (mask - 1) & mask; ss; ss = (ss - 1) & mask) {
            int sub_sum = 0;
            for (int i = 0; i < n; ++i) {
                if (ss & (1 << i)) {
                    sub_sum += a[i];
                }
            }
            if (sub_sum == goal) {
                poss = true;
                break;
            }
        }
    }
    if (poss) {
        cout << "Yes\n" << goal << "\n";
        return 0;
    } else {
        cout << "No\n";
    }
    
    return 0;
}
