#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

vi days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int conv(int m, int d) {
    int res = 0;
    for (int i = 0; i < m; ++i)
        res += days_in_month[i];
    res += d;

    return res;
}

int main() {
    int n;
    cin >> n;
    vi d(n);
    string s, t;
    for (int i = 0; i < n; ++i) {
        cin >> s >> t;
        int mm = 10 * (t[0] - '0') + t[1] - '0';
        int dd = 10 * (t[3] - '0') + t[4] - '0';
        d[i] = conv(mm - 1, dd - 1);
        // cout << mm << ' ' << dd << ' ' << d[i] << '\n';
    }
    sort(all(d));
    d.erase(unique(all(d)), end(d));
    int g = conv(10 - 1, 27 - 1);
    int gap = d[0] + 365 - d.back() - 1;
    int ans = d[0] - 1;
    if (ans < 0)
        ans += 365;

    int m = d.size();
    for (int i = 1; i < m; ++i) {
        int cur_gap = d[i] - d[i - 1] - 1;
        if (cur_gap > gap or (cur_gap == gap and (d[i] - 1 > g and ans < g))) {
            gap = cur_gap;
            ans = d[i] - 1;
        }
    }

    int mm = 0;
    int dd = ans;
    while (dd >= days_in_month[mm]) {
        dd -= days_in_month[mm];
        ++mm;
    }

    printf("%02d-%02d\n", mm + 1, dd + 1);

    return 0;
}
