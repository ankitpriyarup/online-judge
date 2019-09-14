#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 5e5 + 5;
int n;
int a[MAXN];
int b[MAXN];
int dp[MAXN][2][2];

int line(int x, int y, int z) {
    return (a[x] < a[y] and a[y] < a[z]) or (a[x] > a[y] and a[y] > a[z]);
}

// k - was the one before you swapped?
// l - are you swapped?
// return MAX number of << or >>
int solve(int x, int k, int l) {
    if (x == 0) {
        return max(solve(x + 1, l, true), solve(x + 1, l, false));
    }

    // wxy...yyxxww
    int nxt = x + 1;

    int xx = n - 1 - x;
    if (x == xx) {
        return line(x - 1, x, x + 1);
    }

    int w = x - 1;
    int ww = n - 1 - w;
    if (k)
        swap(w, ww);

    if (x + 1 == xx) {
        // w x xx ww

        int cur = 0;
        if (l)
            swap(x, xx);
        cur += line(w, x, xx);
        cur += line(x, xx, ww);

        return cur;
    }

    int& ret = dp[x][k][l];
    if (ret != -1)
        return ret;

    ret = 0;
    int y = x + 1;
    int yy = xx - 1;

    if (l)
        swap(x, xx);
    for (int u = 0; u < 2; ++u) {
        ret = max(ret, line(w, x, y) + line(yy, xx, ww) + solve(nxt, l, u));
        swap(y, yy);
    }

    return ret;
}

int brute() {
    int ans = n + n;
    int h = n / 2;
    for (int m = 0; m < (1 << h); ++m) {
        for (int i = 0; i < n; ++i)
            b[i] = a[i];

        // cout << m << " | ";
        for (int i = 0; i < n - 1 - i; ++i) {
            if (m & (1 << i)) {
                swap(b[i], b[n - 1 - i]);
            }
        }

        int cur = 1;
        for (int i = 1; i + 1 < n; ++i) {
            if (!(b[i - 1] < b[i] and b[i] < b[i + 1]) and !(b[i - 1] > b[i] and b[i] > b[i + 1])) {
                ++cur;
                if (cur >= ans)
                    break;
            }
        }

        /*
        for (int i = 0; i < n; ++i) {
            cout << b[i] << ' ';
        }
        cout << "| " << cur << '\n';
        */

        ans = min(ans, cur);
    }

    return ans;
}

int fast() {
    memset(dp, -1, sizeof(dp));
    return n - 1 - max(solve(0, false, false), solve(0, false, true));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    if (n <= 2) {
        cout << 1 << '\n';
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    /*
    memset(dp, -1, sizeof(dp));
    int ans = n + n;
    for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
            ans = min(ans, solve(0, k, l));
        }
    }
    */

    if (n <= 40)
        cout << brute() << '\n';
    else {
        cout << fast() << '\n';
    }
    
    return 0;
}
