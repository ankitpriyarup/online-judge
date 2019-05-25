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

    constexpr int MAXN = 200005;
    vi freq(MAXN, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++freq[x];
    }

    int pairs = 0;
    for (int i = 0; i < MAXN; ++i) {
        pairs += freq[i] >> 1;
    }

    cout << (pairs >> 1) << '\n';
    
    return 0;
}
