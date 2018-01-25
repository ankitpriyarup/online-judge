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

constexpr int MAXN = 5003;
int n;

// x1 y1 x2 y2
int a[MAXN][4];
vector<int> graph[MAXN];
int in_deg[MAXN];

bool blocks(int i, int j) {
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;

    ax1 = a[i][0];
    ay1 = a[i][1];
    ax2 = a[i][2];
    ay2 = a[i][3];

    bx1 = a[j][0];
    by1 = a[j][1];
    bx2 = a[j][2];
    by2 = a[j][3];

    if (bx1 <= ax1 and ax1 <= bx2) {
        if (bx1 == bx2) {
            int y1 = ay1;
            int y2 = by2;

            return y1 > y2;
        } else {
            int y1 = ay1;
            int y2 = (bx2 - bx1) * by1 + (by2 - by1) * (ax1 - bx1);

            return (bx2 - bx1) * y1 > y2;
        }
    } else if (ax1 <= bx1 and bx1 <= ax2) {
        return !blocks(j, i);
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j)
            scanf("%d", &a[i][j]);

        if (a[i][0] > a[i][2]) {
            swap(a[i][0], a[i][2]);
            swap(a[i][1], a[i][3]);
        }

        for (int k = 1; k < i; ++k) {
            if (blocks(k, i)) {
                // printf("%d -> %d\n", i, k);
                graph[i].push_back(k);
                ++in_deg[k];
            } else if (blocks(i, k)) {
                // printf("%d -> %d\n", k, i);
                graph[k].push_back(i);
                ++in_deg[i];
            }
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (!in_deg[i])
            q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        printf("%d ", u);
        for (int v : graph[u]) {
            if (--in_deg[v] == 0) {
                q.push(v);
            }
        }
    }
    printf("\n");

    return 0;
}
