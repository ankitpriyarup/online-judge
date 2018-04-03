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
using vi = vector<int>;

constexpr int MAXN = 100005;
int n, m;
bool used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    queue<int> q;
    int x;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &x);
        used[x] = true;
        q.push(x);
    }

    for (int i = 1; i <= n; ++i) {
        while (!q.empty() and q.front() <= i) {
            printf("%d\n", q.front());
            q.pop();
        }
        if (!used[i]) {
            printf("%d\n", i);
            used[i] = true;
        }
    }

    return 0;
}
