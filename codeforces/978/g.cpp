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

constexpr int MAXN = 102;
int n, m;
int s[MAXN], d[MAXN], c[MAXN];
int task[MAXN];
vector<int> release[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf(" %d %d %d", &s[i], &d[i], &c[i]);
        release[s[i]].push_back(i);
        task[d[i]] = i;
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    bool poss = true;
    for (int i = 1; i <= n; ++i) {
        for (int exam : release[i]) {
            pq.emplace(d[exam], exam);
        }

        if (task[i] != 0) {
            // printf("Day %d should be doing %d\n", i, task[i]);
            if (c[task[i]]) {
                // printf("%d study days rem\n", c[task[i]]);
                poss = false;
            }
            task[i] = m + 1;
        } else {
            int deadline, idx;
            while (!pq.empty() and !task[i]) {
                tie(deadline, idx) = pq.top();
                pq.pop();

                if (c[idx]) {
                    --c[idx];
                    task[i] = idx;
                    if (c[idx]) {
                        pq.emplace(d[idx], idx);
                    }
                }
            }

            // printf("Day %d study %d\n", i, task[i]);
        }
    }

    if (poss) {
        for (int i = 1; i <= n; ++i) {
            printf("%d%c", task[i], " \n"[i == n]);
        }
    } else {
        printf("-1\n");
    }

    return 0;
}
