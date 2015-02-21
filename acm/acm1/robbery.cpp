#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int T, N, M;
int money[11];
int ds[21];
int de[21];
int dc[21];

bool adjmat[11][11], visited[11];
int main() {
    cin >> T;
    for (int casen = 0; casen < T; casen++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> money[i];
        }

        for (int i = 0; i < M; i++) {
            cin >> ds[i] >> de[i] >> dc[i];
        }

        long long ans = 0LL;
        for (int mask = 0; mask < (1 << M); mask++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    adjmat[i][j] = 0;
                }
                visited[i] = 0;
            }
            long long profit = 0LL;

            //cout << "mask: " << mask << '\n';

            for (int j = 1, p = 0; j <= mask; j *= 2, p++) {
                if (mask & j) {
                    //cout << "p: " << p << '\n';
                    adjmat[ds[p]][de[p]] = 1;        
                    adjmat[de[p]][ds[p]] = 1;        
                    profit -= dc[p];
                    //cout << "profit: " << profit << '\n';
                }
            }

            queue<int> q;
            q.push(0);
            while (!q.empty()) {
                int c = q.front();
                q.pop();
                if (visited[c]) continue;
                visited[c] = true;
                profit += money[c];
                for (int i = 0; i < N; i++) {
                    if (adjmat[c][i] && !visited[i]) {
                        q.push(i);
                    }
                }
            }

            //cout << "profit: " << profit << '\n';
            ans = max(ans, profit);
        }

        cout << ans << '\n';
    }
    return 0;
}
