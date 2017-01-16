#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int num_planets;
const int MAXN = 100005;

pair<long long, int> values[3][MAXN];
int inverse[3][MAXN];

bool visit[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin >> num_planets;

    int x, y, z;
    for (int i = 0; i < num_planets; ++i) {
        cin >> x >> y >> z;
        values[0][i] = make_pair(x, i);
        values[1][i] = make_pair(y, i);
        values[2][i] = make_pair(z, i);
    }

    for (int i = 0; i < 3; ++i) {
        sort(values[i], values[i] + num_planets);
        for (int j = 0; j < num_planets; ++j) {
            inverse[i][values[i][j].second] = j;
        }
    }

    long long ans = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;

    memset(visit, 0, sizeof(visit));
    pq.push(make_pair(0LL, 0));

    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        long long dist = cur.first;
        int loc = cur.second;

        if (visit[loc]) {
            continue;
        }

        visit[loc] = true;
        ans += dist;

        for (int axis = 0; axis < 3; ++axis) {
            int i = inverse[axis][loc];
            if (i > 0) {
                int prev_planet = values[axis][i - 1].second;
                long long new_dist = values[axis][i].first - values[axis][i - 1].first;

                if (!visit[prev_planet]) {
                    pq.push(make_pair(new_dist, prev_planet));
                }
            }

            if (i < num_planets - 1) {
                int next_planet = values[axis][i + 1].second;
                long long new_dist = values[axis][i + 1].first - values[axis][i].first;

                if (!visit[next_planet]) {
                    pq.push(make_pair(new_dist, next_planet));
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
