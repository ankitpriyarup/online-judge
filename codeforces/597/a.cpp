#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll k, a, b;

int main() {
    cin >> k >> a >> b;
    bool zero = a <= 0 and b >= 0;

    ll ans;
    if (zero) {
        ans = b / k + (-a) / k;
    } else {
        ll absa = abs(a);
        ll absb = abs(b);
        ll s = min(absa, absb);
        ll e = max(absa, absb);

        ans = e / k - (s - 1) / k;
    }

    cout << zero + ans << '\n';

    return 0;
}
