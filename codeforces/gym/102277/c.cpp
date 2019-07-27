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
    vi works(10, 1);
    while (n-- > 0) {
        int x;
        cin >> x;
        works[x] = false;
    }

    constexpr int INF = 1e9 + 7;
    vi dist(1000, INF);

    if (works[0]) {
        dist[0] = 0;
    }

    for (int i = 1; i < 1000; ++i) {
        int x = i;
        bool can_use = true;
        while (can_use and x > 0) {
            can_use &= works[x % 10];
            x /= 10;
        }

        if (can_use) {
            dist[i] = 0;
        }
    }

    for (int i = 1; i < 1000; ++i) {
        dist[i] = min(dist[i], 1 + dist[i - 1]);
    }
    for (int i = 998; i >= 0; --i) {
        dist[i] = min(dist[i], 1 + dist[i + 1]);
    }

    int x;
    cin >> x;
    cout << dist[x] << '\n';

    return 0;
}
