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
using vi = vector<int>;

vector<vector<int>> graph = {{}, {2, 3}, {1, 3}, {1, 2, 3}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    set<int> all;
    set<int> person[2];
    for (int k = 0; k < 2; ++k) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            all.insert(x);
            person[k].insert(x);
        }
    }

    int best[4];
    memset(best, 0, sizeof(best));
    for (int x : all) {
        int state = 0;
        if (person[0].find(x) != end(person[0])) {
            state |= 2;
        }

        if (person[1].find(x) != end(person[1])) {
            state |= 1;
        }

        // printf("Show %d has state %d\n", x, state);
        int ans = 1;
        for (int y : graph[state]) {
            ans = max(ans, 1 + best[y]);
        }

        best[state] = max(best[state], ans);
    }

    int ans = 0;
    for (int i = 0; i < 4; ++i) {
        ans = max(ans, best[i]);
    }
    printf("%d\n", ans);

    return 0;
}
