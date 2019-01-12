#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

map<pii, int> memo;

int query(int x, int y) {
    pii state = make_pair(x, y);
    if (memo.find(state) != end(memo))
        return memo[state];

    cout << "? " << x << " " << y << endl;

    int s;
    cin >> s;

    return memo[state] = s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int r, c, k;
    cin >> r >> c >> k;

    // search a 2x2 block
    // 4 cases
    // .U
    // UU
    // must be <= x1, y1
    //
    // .D
    // DD
    // must be > x2, y2
    //
    // .U
    // DD
    
    int lo_c = 1;
    int hi_c = c;

    int lo_r = 1;
    int hi_r = r;
    
    while (lo_c + 1 < hi_c) {
        int mid_c = (lo_c + hi_c) >> 1;

        int mid_r = (lo_r + hi_r) >> 1;
        int x = query(mid_r, mid_c);
        int y = query(mid_r, mid_c + 1);

        if (x > y) {
            lo_c = mid_c + 1;
        } else {
            hi_c = mid_c;
        }

        if (lo_r + 1 < hi_r) {
            int z = query(mid_r + 1, mid_c);
            if (x > z) {
                lo_r = mid_r + 1;
            } else {
                hi_r = mid_r;
            }
        }
    }

    while (lo_r + 1 < hi_r) {
        int mid_r = (lo_r + hi_r) >> 1;
        if (query(mid_r, lo_c) > query(mid_r + 1, lo_c)) {
            lo_r = mid_r + 1;
        } else {
            hi_r = mid_r;
        }
    }

    int ans = 2e9 + 2;
    for (int dx = 0; dx <= 1; ++dx)
        for (int dy = 0; dy <= 1; ++dy)
            if (lo_r + dx <= r and lo_c + dy <= c)
                ans = min(ans, query(lo_r + dx, lo_c + dy));

    cout << "! " << ans << '\n';
    /*
    // manhattan distance is independent. If we fix some row / col, we can find the min one
    // answer: use row 0 and t-search for min cost
    // fix the col and t-search again to find row
    int lo = 1;
    int hi = c;
    while (lo + 1 < hi) {
        // issue with ternary search: equal values
        // could be 
        //    v      v
        // ------------\/
        // ------\/------
        // 
        // but the only fixed values should be the minimum?
        // when you increase by 1, what happens
        // everything < you increases by 1
        // everything > you decreases by 1
        // so if two adjacent things are 0, then you're at the minimum
        // otherwise you know what side
        int mid = (lo + hi) >> 1;
        if (query(1, mid) > query(1, mid + 1)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    int col = query(1, lo) < query(1, hi) ? lo : hi;
    lo = 1;
    hi = r;
    while (lo + 1 < hi) {
        int mid = (lo  + hi) >> 1;
        if (query(mid, col) > query(mid + 1, col)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }

    int res = min(query(lo, col), query(hi, col));
    cout << "! " << res << '\n';
    */

    return 0;
}
