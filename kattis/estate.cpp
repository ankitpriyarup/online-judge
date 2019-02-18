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

    constexpr int MAXV = 1000001;
    vi f(MAXV, 1);
    f[0] = f[1] = 0;
    for (int d = 2; d < MAXV; ++d) {
        int sum = 0;
        for (int i = 2; i < 2 + d; ++i) {
            sum += i;
        }
        if (sum >= MAXV) break;
        for (int i = 2; sum < MAXV; ++i) {
            ++f[sum];
            sum -= i;
            sum += i + d;
        }
    }

    int n;
    while (cin >> n) {
        if (!n) break;
        cout << f[n] << '\n';
    }
    
    return 0;
}
