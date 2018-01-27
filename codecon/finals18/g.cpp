#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 5;
int n;
int e[MAXN], r[MAXN], speeds[MAXN][MAXN];
int T;

bool done[8][200005][5][5];
int dp[8][200005][5][5];

int h(const vector<int>& cur) {
    int res = 0;
    for (int x : cur) {
        res *= 15;
        res += x;
    }

    return res;
}

vector<int> go(const vector<int>& cur, int a, int b) {
    vector<int> res(begin(cur), end(cur));
    for (int i = 0; i < 5; ++i) {
        if (i != a and i != b)
            res[i] = min(e[i], res[i] + r[i]);
        else
            res[i] -= r[i];
    }

    return res;
}

vector<int> rested(const vector<int>& cur) {
    vector<int> res(begin(cur), end(cur));
    for (int i = 0; i < 5; ++i) {
        res[i] = min(e[i], res[i] + r[i]);
    }

    return res;
}

int solve(int time, const vector<int>& cur, int a, int b) {
    if (time == T) {
        return 0;
    }

    int hc = h(cur);
    if (done[time][hc][a][b]) {
        /*
        cout << time << ' ';
        for (int x : cur)
            cout << x << ' ';
        cout << '(' << a << ", " << b << ")\n";

        cout << "= " << dp[time][hc][a][b] << "\n";
        */
        return dp[time][hc][a][b];
    }

    int ret = -1e9;
    // rest
    ret = max(ret, -200 + solve(time + 1, rested(cur), a, b));

    // keep going
    int speed = speeds[a][b];
    if (cur[a] >= r[a] and cur[b] >= r[b]) {
        ret = max(ret, (100 * speed) + solve(time + 1, go(cur, a, b), a, b));
    }

    // swap
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int speed = speeds[i][j];
            if (cur[i] >= r[i] and cur[j] >= r[i]) {
                ret = max(ret, -200 + 100 * speed + solve(time + 1, go(cur, i, j), i, j));
            }
        }
    }

    done[time][hc][a][b] = true;
    /*
    cout << time << ' ';
    for (int x : cur)
        cout << x << ' ';
    cout << '(' << a << ", " << b << ")\n";

    cout << "= " << ret << "\n";
    */
    return dp[time][hc][a][b] = ret;
}

int main() {
    cin >> n;
    string name;

    vector<int> energies(n);
    for (int i = 0; i < n; ++i) {
        cin >> name >> e[i] >> r[i];
        energies[i] = e[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> speeds[i][j];
        }
    }

    cin >> T;

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ans = max(ans, solve(0, energies, i, j));

    cout << ans << '\n';

    return 0;
}
