#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int N, M;
bool adjmat[3003][3003];
int counts[3003];
int bfs(int x) {
    queue<pair<int, int> > q;
    q.push(make_pair(x, 0));

    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        if (node.second == 2) {
            counts[node.first]++;
        } else {
            for (int i = 0; i < N; i++) {
                if (adjmat[i][node.first]) {
                    q.push(make_pair(i, node.second + 1));
                }
            }
        }
    }

    int ret = 0;

//    cout << "bfs: " << x << '\n';
//    for (int i = 0; i < N; i++) {
//        cout << counts[i] << " ";
//    }
//    cout << '\n';
    for (int i = 0; i < N; i++) {
        if (i != x && counts[i] > 0) {
            ret += (counts[i]) * (counts[i] - 1) / 2;
        }
    }

    return ret;
}

int main() {
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        a--;
        b--;
        adjmat[a][b] = true;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        memset(counts, 0, sizeof(counts));
        ans += bfs(i);
    }

    cout << ans << '\n';
    return 0;
}
