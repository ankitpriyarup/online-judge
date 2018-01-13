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
char target[1000006];
int m;
int n;
bool has[MAXN][26];
vector<int> by_char[26];
bool used[MAXN];

bool dfs(int p) {
    if (p == m) {
        return true;
    }

    for (int cube : by_char[target[p] - 'a']) {
        if (!used[cube]) {
            used[cube] = true;
            if (dfs(p + 1))
                return true;
            used[cube] = false;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s %d", target, &n);
    m = strlen(target);
    char buf[3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            scanf("%s", buf);
            if (buf[0] <= '9')
                continue;
            has[i][buf[0] - 'a'] = true;
        }
    }

    for (int j = 0; j < 26; ++j) {
        for (int i = 0; i < n; ++i) {
            if (has[i][j])
                by_char[j].push_back(i);
        }
    }

    printf("%s\n", dfs(0) ? "YES" : "NO");

    return 0;
}
