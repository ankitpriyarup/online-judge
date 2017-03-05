#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

const int MAXN = 102;

int n;
vector<pair<int, int> > intervals;
bool visit[MAXN];

bool overlap(int a, int b) {
    return (intervals[b].first < intervals[a].first and intervals[a].first < intervals[b].second)
        or (intervals[b].first < intervals[a].second and intervals[a].second < intervals[b].second);
}

bool solve(int a, int b) {
    memset(visit, 0, sizeof(visit));

    queue<int> q;
    q.push(a);
    visit[a] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == b)
            return true;

        for (size_t i = 1; i <= intervals.size(); ++i) {
            if (cur != i and !visit[i] and overlap(cur, i)) {
                visit[i] = true;
                q.push(i);
            }
        }
    }

    return false;
}

int main() {
    scanf("%d", &n);
    int type;
    intervals.push_back(make_pair(0, 0));

    int a, b;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &type, &a, &b);

        if (type == 2) {
            bool passable = solve(a, b);

            if (passable) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            intervals.push_back(make_pair(a, b));
        }
    }

    return 0;
}
