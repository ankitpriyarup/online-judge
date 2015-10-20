#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int points[1010][3];
bool adjmat[1010][1010]; // directed, i -> j
bool seen[1010];
int outdegree[1010];
int best[1010];

int main() {
    int T, N, R;
    cin >> T;
    for(int ttt=0;ttt<T;ttt++) {
        cin >> N >> R;
        for(int i=0;i<N;i++) {
            cin >> points[i][0] >> points[i][1] >> points[i][2];
            outdegree[i] = 0;
            best[i] = 0;
            seen[i] = 0;
        }

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(i == j || points[i][1] < points[j][1]) {
                    adjmat[i][j] = 0;
                    continue;
                }
                int delx = points[i][0] - points[j][0];
                delx = delx < 0 ? -1 * delx : delx;
                int dely = points[i][1] - points[j][1];
                if(delx <= R*dely) {
                    adjmat[i][j] = 1;
                    outdegree[i]++;
                } else {
                    adjmat[i][j] = 0;
                }
            }
        }
        /*
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cout << adjmat[i][j] << " ";
            }
            cout << endl;
        }
            */
        queue<int> q;
        for(int i=0;i<N;i++) {
            if(outdegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int c = q.front();
            q.pop();
            if(seen[c]) continue;
            seen[c] = true;

            int ans = 0;

            for(int i=0;i<N;i++) {
                if(adjmat[c][i]) {
                    ans = max(ans, best[i]);
                }
                if(adjmat[i][c]) {
                    outdegree[i]--;
                    if(outdegree[i] == 0) {
                        q.push(i);
                    }
                }
            }
            ans += points[c][2];
            best[c] = ans;
        }

        int ans = 0;
        for(int i=0;i<N;i++) {
            ans = max(ans, best[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
