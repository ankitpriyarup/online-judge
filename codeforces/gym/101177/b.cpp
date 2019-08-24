#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXR = 1e6 + 1;
constexpr int MAXN = 2e5 + 5;
int a[MAXR];
int p = 0;
vector<pii> graph[MAXN];

void create(int color, int time) {
    a[p++] = color;
    if (p >= MAXR) return;
    int k = graph[color].size();
    for (int i = k - 1; p < MAXR and i >= 0; --i) {
        int t, c;
        tie(t, c) = graph[color][i];
        if (t < time) break;

        create(c, t + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].emplace_back(i, y);
    }

    create(0, 0);

    for (int i = l; i < r; ++i) {
        cout << a[i % p] << ' ';
    }

    return 0;
}
