#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

class MedianFaking {
public:
    vector<int> minimize(int F, int M, vector<int> data, int goal) {
        // find the current median
        int S = F * M;
        vector<int> agg(all(data));
        sort(all(agg));
        int mid = (S - 1) / 2;
        int cur_med = agg[mid];
        if (cur_med == goal) {
            return {0, 0};
        }

        bool neg = cur_med < goal;
        int diff = 0;
        if (neg) {
            for (int i = mid; i < data.size(); ++i) {
                if (agg[i] >= goal) break;
                ++diff;
            }
        } else {
            for (int i = mid; i >= 0; --i) {
                if (agg[i] <= goal) break;
                ++diff;
            }
        }

        // cout << "DIFF " << diff << '\n';

        vector<int> scores;
        for (int i = 0; i < F; ++i) {
            int score = 0;
            for (int j = 0; j < M; ++j) {
                int idx = M * i + j;
                if ((!neg and data[idx] > goal) or (neg and data[idx] < goal)) {
                    ++score;
                }
            }
            // cout << score << '\n';
            scores.push_back(score);
        }

        sort(all(scores));
        vector<int> ans(2, 0);
        while (diff != 0) {
            int take = min(diff, scores.back());
            scores.back() -= take;
            diff -= take;
            if (scores.back() == 0) {
                scores.pop_back();
            }

            ++ans[0];
            ans[1] += take;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    MedianFaking mf;
    vi res = mf.minimize(4, 3, {3,8,12, 3,8,12, 3,8,12, 8,12,17}, 12);
    // 0 1 2 3 4 5 6 7  8  9  10 11
    // 3 3 3 8 8 8 8 12 12 12 12 17
    cout << res[0] << ' ' << res[1] << '\n';

    return 0;
}
