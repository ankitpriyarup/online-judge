/*
ID: rednano1
PROG: ditch
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int N, M;

long long graph[202][202];
long long residual[202][202];
int previous[202];
bool visited[202];

int bfs(int source, int sink) {
    memset(previous, -1, sizeof(previous));
    memset(visited, 0, sizeof(visited));

    queue<int> q;

    q.push(source);
    visited[source] = true;

    bool found_sink = false;
    while (!found_sink && !q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < M; ++i) {
            if (!visited[i] and residual[cur][i] > 0) {
                q.push(i);
                visited[i] = true;
                previous[i] = cur;

                found_sink = (i == sink);
                if (found_sink) {
                    break;
                }
            }
        }
    }

    return found_sink;
}

long long ford_fulkerson(int source, int sink) {
    memcpy(residual, graph, sizeof(residual));
    long long ans = 0;

    while (bfs(source, sink)) {
        // update the path
        int cur = sink;
        long long max_path = INF;
        while (cur != source) {
            int last = previous[cur];
            max_path = min(max_path, residual[last][cur]);

            cur = last;
        }

        cur = sink;
        while (cur != source) {
            int last = previous[cur];
            residual[last][cur] -= max_path;
            residual[cur][last] += max_path;

            cur = last;
        }

        ans += max_path;
    }

    return ans;
}

int main() {
    ifstream fin("ditch.in");
    ofstream fout("ditch.out");

    fin >> N >> M;
    int x, y, w;

    for (int i = 0; i < N; ++i) {
        fin >> x >> y >> w;
        x--; y--;
        graph[x][y] += w;
    }

    fin.close();

    fout << ford_fulkerson(0, M - 1) << '\n';

    return 0;
}
