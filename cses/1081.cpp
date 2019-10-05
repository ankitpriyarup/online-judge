#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXX = 1e6 + 1;
int occ[MAXX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++occ[x];
    }

    for (int i = MAXX - 1; i > 0; --i) {
        int cur = 0;
        for (int j = i; cur < 2 and j < MAXX; j += i) {
            cur += occ[j];
        }

        if (cur >= 2) {
            cout << i << '\n';
            return 0;
        }
    }
    
    return 0;
}
