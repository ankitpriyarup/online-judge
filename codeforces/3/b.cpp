#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
using ll = long long;
using pii = pair<ll, int>;

int main() {
    int n, v;
    scanf("%d %d", &n, &v);
    vector<vector<pii> > by_w(2, vector<pii>());

    int t, p;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &t, &p);
        --t;
        by_w[t].push_back({p, i + 1});
    }

    for (int k = 0; k < 2; ++k) {
        sort(begin(by_w[k]), end(by_w[k]));
        reverse(begin(by_w[k]), end(by_w[k]));
    }

    for (int k = 0; k < 2; ++k) {
        for (int i = 1; i < by_w[k].size(); ++i) {
            by_w[k][i].first += by_w[k][i - 1].first;
        }
    }

    ll score = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i <= by_w[1].size(); ++i) {
        int rem = min(v - 2 * i, (int) by_w[0].size());
        if (rem < 0)
            break;

        ll cur = 0LL;
        if (i) {
            cur += by_w[1][i - 1].first;
        }

        if (rem) {
            cur += by_w[0][rem - 1].first;
        }

        if (cur > score) {
            score = cur;
            a = rem;
            b = i;
        }
    }

    printf("%I64d\n", score);
    vector<int> inds;
    for (int i = 0; i < a; ++i) {
        inds.push_back(by_w[0][i].second);
    }
    for (int i = 0; i < b; ++i) {
        inds.push_back(by_w[1][i].second);
    }
    sort(begin(inds), end(inds));
    for (int x : inds) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}
