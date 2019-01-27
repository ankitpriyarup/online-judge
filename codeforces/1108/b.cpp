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
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(all(a));

    int x = a.back();
    vi d;
    for (int i = 1; i <= x; ++i) {
        if (x % i == 0)
            d.push_back(i);
    }

    while (!d.empty() and d.back() == a.back()) {
        d.pop_back();
        a.pop_back();
    }

    cout << x << " " << a.back() << '\n';
    
    return 0;
}
