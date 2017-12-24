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

vector<int> graph[10];
int degree[10];
char name[10][30], nation[10][30], league[10][30], team[10][30];
bool used[10];
bool flag;
int perm[10];

int get_score(int i, int j) {
    if (i == -1 or j == -1) return 10000;
    if (strcmp(nation[i], nation[j]) == 0 and strcmp(team[i], team[j]) == 0) {
        return 3;
    }
    if (strcmp(nation[i], nation[j]) == 0 and strcmp(league[i], league[j]) == 0) {
        return 2;
    }
    if (strcmp(team[i], team[j]) == 0) {
        return 2;
    }
    if (strcmp(league[i], league[j]) == 0) {
        return 1;
    }
    if (strcmp(nation[i], nation[j]) == 0) {
        return 1;
    }

    return 0;
}

bool check() {
    for (int i = 0; i < 10; ++i) {
        if (perm[i] == -1) continue;

        int score = 0;
        for (int j : graph[i]) {
            score += get_score(perm[i], perm[j]);
        }

        if (score < degree[i]) return false;
    }

    return true;
}

void dfs(int pos) {
    if (flag) return;

    if (pos == 10) {
        if (check())
            flag = true;
        return;
    }

    for (int i = 0; i < 10; ++i) {
        if (used[i]) continue;

        perm[pos] = i;
        used[i] = true;
        dfs(pos + 1);
        used[i] = false;
        perm[pos] = -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    scanf("%d", &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);

        ++degree[u];
        ++degree[v];
    }

    for (int i = 0; i < 10; ++i) {
        scanf("%s %s %s %s", name[i], nation[i], league[i], team[i]);
    }

    flag = false;
    memset(perm, -1, sizeof(perm));
    dfs(0);

    printf("%s\n", flag ? "yes" : "no");

    return 0;
}
