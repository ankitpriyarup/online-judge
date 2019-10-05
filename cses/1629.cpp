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
    vector<pii> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(all(movies));

    int ans = 0;
    int last = -1;
    for (auto& movie : movies) {
        if (movie.second >= last) {
            ++ans;
            last = movie.first;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
