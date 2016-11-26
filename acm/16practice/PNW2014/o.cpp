#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    int N;
    vector<pair<int, int> > diamonds;
    vector<int> dp;

    double x, y;
    while (T-- > 0) {
        diamonds.clear();
        dp.clear();

        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> x >> y;
            int ix = 100 * x;
            int iy = -100 * y;
            diamonds.push_back(make_pair(ix, iy));
        }

        int best = 1;
        for (int i = 0; i < N; ++i) {
            dp.push_back(1);
            for (int j = 0; j < i; ++j) {
                if (diamonds[j].first < diamonds[i].first and diamonds[j].second < diamonds[i].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            best = max(best, dp[i]);
        }

        cout << best << '\n';
    }

    return 0;
}
