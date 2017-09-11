#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using ll = long long;
using pt = pair<int, int>;

constexpr int MAXW = 1003;
int w, p;
pt wells[MAXW];
pair<pt, pt> pipes[MAXW];

vector<int> graph[MAXW];

pt operator-(const pt& a, const pt& b) {
    return {a.first - b.first, a.second - b.second};
}

ll operator^(const pt& a, const pt& b) {
    return a.first * b.second - a.second * b.first;
}

ll sgn(ll x) {
    if (x < 0) {
        return -1;
    } else if (x == 0) {
        return 0;
    } else {
        return 1;
    }
}

bool intersect(int a, int b) {
    pt a1 = pipes[a].first;
    pt a2 = pipes[a].second;

    pt b1 = pipes[b].first;
    pt b2 = pipes[b].second;

    if (a1 == b1) {
        return false;
    }

    if (a2 == b2) {
        return true;
    }

    return sgn((a2 - a1) ^ (b1 - a1)) != sgn((a2 - a1) ^ (b2 - a1))
       and sgn((b2 - b1) ^ (a1 - b1)) != sgn((b2 - b1) ^ (a2 - b1));
}

int visit[MAXW];
bool flag = true;
void dfs(int node, int color) {
    visit[node] = color;

    for (int child : graph[node]) {
        if (!visit[child]) {
            dfs(child, !color);
        }

        if (visit[child] == visit[node]) {
            flag = false;
            break;
        }
    }
}

int main() {
    scanf("%d %d", &w, &p);

    int s, x, y;
    for (int i = 0; i < w; ++i) {
        scanf("%d %d", &x, &y);
        wells[i] = {x, y};
    }

    for (int i = 0; i < p; ++i) {
        scanf("%d %d %d", &s, &x, &y);
        pipes[i] = {wells[s - 1], {x, y}};

        for (int j = 0; j < i; ++j) {
            if (intersect(i, j)) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    flag = true;
    for (int i = 0; i < p; ++i) {
        if (!visit[i]) {
            dfs(i, 0);
        }
    }

    printf("%s\n", flag ? "possible" : "impossible");

    return 0;
}
