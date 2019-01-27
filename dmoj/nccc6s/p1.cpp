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
    scanf(" %d", &n);
    ll sum = 0LL;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf(" %d", &x);
        sum += x;
    }

    printf("%.1lf\n", (double)sum / n);
    
    return 0;
}
