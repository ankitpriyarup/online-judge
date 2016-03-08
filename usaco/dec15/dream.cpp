#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int grid[1001][1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool seen[1001][1001][2]; // x y smell

struct state {
    int x, y, dist;
    bool smell;
    state(int x, int y, bool smell, int dist): x(x), y(y), dist(dist), smell(smell) {};

    bool operator< (const state& other) const {
        return dist >= other.dist;
    }
};

bool bad(int x, int y, bool smell) {
    return x < 0 || y < 0 || x >= N || y >= M || grid[x][y] == 0 || (!smell && grid[x][y] == 3);
}

int main() {
    ifstream fin("dream.in");
    ofstream fout("dream.out");

    fin >> N >> M;

    for (int i = 0 ; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            fin >> grid[i][j];
        }
    }

    memset(seen, 0, sizeof(seen));
    priority_queue<state> pq;
    pq.push(state(0, 0, 0, 0));
    seen[0][0][0] = 1;

    int ans = -1;
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        //printf("At state: (%d, %d, %d, %d)\n", cur.x, cur.y, cur.smell, cur.dist);

		if (cur.x == N - 1 && cur.y == M - 1) {
            ans = cur.dist;
            break;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (bad(nx, ny, cur.smell))
                continue;

            bool smell = cur.smell || grid[nx][ny] == 2;

            if (seen[nx][ny][smell]) 
                continue;

            // handle purple tiles
            if (grid[nx][ny] != 4) {
                pq.push(state(nx, ny, smell, cur.dist + 1));
                seen[nx][ny][smell] = 1;
            }
            else {
                int delta = 1;
                while (nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] == 4) {
                    int nnx = nx + dx[d];
                    int nny = ny + dy[d];
                    if (bad(nnx, nny, 0))
                        break;

                    nx = nnx;
                    ny = nny;
                    delta += 1;
                }

                if (seen[nx][ny][grid[nx][ny] == 2])
                    continue;

                pq.push(state(nx, ny, grid[nx][ny] == 2, cur.dist + delta));
                seen[nx][ny][grid[nx][ny] == 2] = 1;
            }
        }
    }

    fout << ans << '\n';
    return 0;
}

