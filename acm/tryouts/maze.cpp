#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
char board[101][101];
bool seen[101][101][4];
int dx4[] = {1, 0, -1, 0};
int dy4[] = {0, 1, 0, -1};

struct node {
    int x, y, dir, score;
    node(int x, int y, int dir, int score): x(x), y(y), dir(dir), score(score) {};
};

bool operator<(node a, node b) {
    return a.score > b.score;
}

int main() {
    int T, r, c;
    cin >> T;
    for(int ttt=0;ttt<T;ttt++) {
        cin >> r >> c;
        int sx = 0;
        int sy = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin >> board[i][j];
                for(int k=0;k<4;k++) {
                    seen[i][j][k] = false;
                }
                if(board[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }
        // start at 0, 0, dir and bfs based on score
        priority_queue<node> pq;
        pq.push(node(sx, sy, 0, 0));
        pq.push(node(sx, sy, 1, 0));
        pq.push(node(sx, sy, 2, 0));
        pq.push(node(sx, sy, 3, 0));
        int ans = -1;
        while(!pq.empty()) {
            node n = pq.top();
            pq.pop();
            if(n.x < 0 || n.x >= r || n.y < 0 || n.y >= c || board[n.x][n.y] == '#' || seen[n.x][n.y][n.dir]) continue;
            seen[n.x][n.y][n.dir] = true;
            //cout << n.x << " " << n.y << " " << n.dir << " " << n.score << endl;
            if(board[n.x][n.y] == 'E') {
                ans = n.score;
                break;
            }
            for(int d=0;d<4;d++) {
                pq.push(node(n.x+dx4[d], n.y+dy4[d], d, n.score + (n.dir == d ? 0 : 1)));
            }
        }
        if(ans == -1) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
