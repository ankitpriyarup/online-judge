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
    int tc = 1;
    auto comp = [](const string& a, const string& b) {
        if (a.size() == b.size()) {
            return a < b;
        }

        return a.size() > b.size();
    };

    while (T-- > 0) {
        int n;
        cin >> n;
        vector<string> words(n);
        map<string, vector<int>, decltype(comp)> tot(comp);
        for (int i = 0; i < n; ++i) {
            cin >> words[i];
            for (int j = 0; j < words[i].size(); ++j) {
                string t = words[i].substr(j);
                tot[t].push_back(i);
            }
        }

        vector<bool> vis(n, false);
        int ans = 0;
        for (auto& p : tot) {
            int x = -1;
            int y = -1;
            for (auto& idx : p.second) {
                if (vis[idx]) continue;
                if (x == -1) {
                    x = idx;
                } else {
                    y = idx;
                    break;
                }
            }
            if (x != -1 and y != -1) {
                vis[x] = true;
                vis[y] = true;
                ans += 2;
            }
        }

        cout << "Case #" << tc++ << ": " << ans << '\n';
    }
    
    return 0;
}
