#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

class ChangeDistances {
public:
    vector<string> findGraph(vector<string> g) {
        int n = g.size();
        // consider some pair u, v in G
        // 3 cases for dist
        // dist = 1, then our dist != 1 because no direct edge
        // dist = inf, our dist = 1
        // dist != 1, our dist = 1
        vector<string> h(n, string(n, '0'));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                h[i][j] = '0' + ((g[i][j] - '0') ^ 1);
            }
        }

        return h;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    return 0;
}
