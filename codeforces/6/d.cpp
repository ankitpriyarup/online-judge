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

constexpr int INF = 1e9 + 7;
int n, a, b;
int h[20];
int dp[30][30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &a, &b);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", h + i);
        ++h[i];
    }

    vector<int> moves;
    while (h[1] > 0) {
        moves.push_back(2);
        h[1] -= b;
        h[2] -= a;
        h[3] -= b;
    }

    while (h[n] > 0) {
        moves.push_back(n - 1);
        h[n - 2] -= b;
        h[n - 1] -= a;
        h[n]     -= b;
    }

    vector<int> state;
    for (int i = 2; i < n; ++i)
        state.push_back(h[i]);

    queue<vector<int> > q;
    q.push(state);

    map<vector<int>, int> previous;
    previous[state] = -1;

    int lvl = 0;
    vector<int> cur;
    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();

        /*
        printf("Visiting:\n");
        for (int x : v)
            printf("%d ", x);
        printf("\n");
        */

        int s = 0;
        for (int x : v)
            s += max(0, x);

        if (s == 0) {
            cur = v;
            break;
        }

        for (int i = 0; i < state.size(); ++i) {
            if (state[i] > 0) {
                vector<int> v2(begin(v), end(v));
                if (i - 1 >= 0) {
                    v2[i - 1] -= b;
                }
                v2[i] -= a;
                if (i + 1 < state.size()) {
                    v2[i + 1] -= b;
                }

                if (previous.find(v2) != end(previous))
                    continue;

                previous[v2] = i;
                q.push(v2);
            }
        }
    }

    /*
    printf("State:\n");
    for (int x : state)
        printf("%d ", x);
    printf("\n");
    */

    while (cur != state) {
        /*
        printf("Cur:\n");
        for (int x : cur)
            printf("%d ", x);
        printf("\n");
        */

        moves.push_back(previous[cur] + 2);
        int x = previous[cur];
        cur[x] += a;
        if (x > 0)
            cur[x - 1] += b;
        if (x + 1 < cur.size())
            cur[x + 1] += b;
    }

    printf("%lu\n", moves.size());
    for (int x : moves)
        printf("%d ", x);
    printf("\n");

    return 0;
}
