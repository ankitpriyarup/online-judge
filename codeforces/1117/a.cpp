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
    int m = -1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m = max(m, a[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < m) continue;

        int j = i;
        while (j + 1 < n and a[j + 1] == a[j]) {
            ++j;
        }
        ans = max(ans, j - i + 1);
        i = j;
    }
    
    printf("%d\n", ans);
    return 0;
}
