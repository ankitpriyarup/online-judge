#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m;

struct shape {
    long long area;
    map<int, int, greater<int> > m;

    shape(): area(0LL) {}

    shape(const int& x): area(x) {
        m[x] = 1;
    }

    void restrict(const int& w) {
        int restricted = 0;

        auto it = m.begin();
        while (it != m.end() and it->first >= w) {
            area -= 1LL * (it->first - w) * it->second;
            restricted += it->second;
            ++it;
        }

        m.erase(m.begin(), it);

        m[w] += restricted;
    }

    void insert(const int& x) {
        area += x;
        m[x]++;
    }

    inline void clear() {
        area = 0LL;
        m.clear();
    }
};

int get_index(const vvi& v, int row, int c1, int c2, int target) {
    // find largest c in range such that v[row][c] <= target
    // if no such c exists, return -1
    
    if (v[row][c1] > target) {
        return -1;
    }
    if (v[row][c2] <= target) {
        return c2;
    }

    int lo = c1;
    int hi = c2;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (v[row][mid] <= target) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    
    return lo;
}

int main() {
    scanf("%d %d", &n, &m);
    vvi v(n, vi(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &v[i][j]);
        }
    }

    // dp[i][j] = max k such that v[i][j..j+k) is sorted
    vvi dp(n, vi(m, 1));

    for (int i = 0; i < n; ++i) {
        for (int j = m - 2; j >= 0; --j) {
            if (v[i][j] <= v[i][j + 1]) {
                dp[i][j] = 1 + dp[i][j + 1];
            }
        }
    }

    long long ans = 0LL;
    vector<shape> shapes(m);
    for (int j = 0; j < m; ++j) {
        shapes[j] = shape(dp[n - 1][j]);
        ans += dp[n - 1][j];
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            int ind = get_index(v, i, j, j + dp[i][j] - 1, v[i + 1][j]);

            if (ind == -1) {
                shapes[j].clear();
            } else {
                int width = ind - j + 1;
                shapes[j].restrict(width);
            }

            shapes[j].insert(dp[i][j]);

            ans += shapes[j].area;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
