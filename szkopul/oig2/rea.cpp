#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

constexpr int MAXN = 1e6 + 6;
constexpr int MAXR = 1e5 + 5;
int n, k, r;
bool have[MAXN];
int in_deg[MAXR];
vector<int> inputs[MAXN];
vector<int> outputs[MAXR];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &k, &r);
    int x;
    queue<int> q;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        have[x] = true;
        q.push(x);
    }

    int len;
    for (int i = 0; i < r; ++i) {
        scanf("%d", &len);
        for (int j = 0; j < len; ++j) {
            scanf("%d", &x);
            inputs[x].push_back(i);
            ++in_deg[i];
        }

        scanf("%d", &len);
        for (int j = 0; j < len; ++j) {
            scanf("%d", &x);
            outputs[i].push_back(x);
        }
    }

    int ans = -k;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ++ans;

        for (int reaction : inputs[cur]) {
            if (--in_deg[reaction] == 0) {
                for (int chem : outputs[reaction]) {
                    if (!have[chem]) {
                        have[chem] = true;
                        q.push(chem);
                    }
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
