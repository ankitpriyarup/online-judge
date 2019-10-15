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
    bitset<100001> bs;
    bs[0] = true;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        bs = bs | (bs << x);
    }

    cout << bs.count() - 1 << '\n';
    for (int i = 1; i <= 100000; ++i) {
        if (bs[i]) cout << i << ' ';
    }
    
    return 0;
}
