#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 100005;
int n;
int a[MAXN];
int b[MAXN];

constexpr int DEBUG = 0;

ll brute() {
    vector<ll> init(n);
    for (int i = 0; i < n; ++i) {
        init[i] = a[i];
    }

    set<vector<ll>> seen;
    queue<vector<ll>> q;
    q.push(init);
    seen.insert(init);

    ll ans = -1e18;

    while (!q.empty()) {
        vector<ll> cur = q.front();
        q.pop();

        /*
        for (ll x : cur) {
            cout << x << ' ';
        }
        cout << '\n';
        */

        if (cur.size() == 1) {
            ans = max(ans, cur[0]);
            continue;
        }

        int m = cur.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == j) continue;

                vector<ll> nxt;
                for (int k = 0; k < m; ++k) {
                    if (i == k or j == k) continue;
                    nxt.push_back(cur[k]);
                }

                nxt.push_back(cur[i] - cur[j]);
                sort(all(nxt));
                if (!seen.count(nxt)) {
                    seen.insert(nxt);
                    q.push(nxt);
                }
            }
        }
    }

    return ans;
}

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
}

void gen() {
    srand(time(0));

    n = 3 + (rand() % 5);
    for (int i = 0; i < n; ++i) {
        int sgn = (rand() & 1) ? -1 : 1;
        a[i] = (rand() % 10) * sgn;
    }
    sort(a, a + n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    read();
    // gen();

    ll exp = 0;
    if (DEBUG)
        exp = brute();

    for (int i = 0; i < n; ++i)
        b[i] = a[i];

    vector<pair<ll, ll>> moves;
    // get down to 1 negative number
    int l = 0;
    while (l + 1 < n - 1 and b[l + 1] <= 0) {
        moves.emplace_back(b[n - 1], b[l]);
        b[n - 1] -= b[l];
        ++l;
    }

    // l points to the <= 0, everything after is pos
    for (int i = l + 1; i < n - 1; ++i) {
        moves.emplace_back(b[l], b[i]);
        b[l] -= b[i];
    }

    moves.emplace_back(b[n - 1], b[l]);
    ll res = b[n - 1] - b[l];

    if (DEBUG) {
        cout << n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';

        cout << res << ' ' << exp << '\n';
        assert(res == exp);
    }

    cout << res << '\n';
    for (auto& p : moves) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
