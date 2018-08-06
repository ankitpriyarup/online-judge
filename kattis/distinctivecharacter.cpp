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

constexpr int MAXN = 100005;
constexpr int MAXK = 22;
constexpr int INF = 1e9 + 7;
int n, k;
char buf[MAXK];
char buf2[MAXK];

int parse() {
    int x = 0;
    for (int i = 0; i < k; ++i) {
        x <<= 1;
        x |= (buf[i] == '1');
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    vector<int> dist(1 << k, INF);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        scanf(" %s", buf);
        int x = parse();
        q.push(x);
        dist[x] = 0;
    }

    while (!q.empty()) {
        int sz = q.size();
        while (sz-- > 0) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < k; ++i) {
                int y = x ^ (1 << i);
                if (dist[y] == INF) {
                    dist[y] = dist[x] + 1;
                    q.push(y);
                }
            }
        }
    }

    int x = 0;
    for (int i = 0; i < (1 << k); ++i) {
        if (dist[i] > dist[x])
            x = i;
    }

    for (int i = 0; i < k; ++i) {
        buf2[k - i - 1] = "01"[(x & (1 << i)) > 0];
    }

    printf("%s\n", buf2);

    return 0;
}
