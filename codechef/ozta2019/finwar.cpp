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

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m, s;
        cin >> n >> m >> s;
        vi a(n);
        vi p(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            p[i + 1] = p[i] + a[i];
        }

        // can we partition a into m segments such that
        // every segment has sum <= s?
        // seems greedy - go as far as you can
        int needed = 0;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            int sum = a[i];
            while (j < n and sum + a[j] <= s)
                sum += a[j++];

            if (sum > s) {
                needed = m + m;
                break;
            }

            ++needed;
            i = j - 1;
        }

        cout << (needed <= m ? "YES" : "NO") << '\n';
    }
    
    return 0;
}
