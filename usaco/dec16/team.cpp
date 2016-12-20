#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n, m, max_team_size;
int john[1003];
int paul[1003];

// dp[k][i][j] - How many sets of k cows can fj choose from first i and fp
// choose from first j such that fj beats fp?
long long dp[11][1003][1003];

const int MOD = 1000000009;

int main() {
    ifstream fin("team.in");
    ofstream fout("team.out");

    fin >> n >> m >> max_team_size;

    for (int i = 0; i < n; ++i) {
        fin >> john[i];
    }
    sort(john, john + n);

    for (int i = 0; i < m; ++i) {
        fin >> paul[i];
    }
    sort(paul, paul + m);

    memset(dp, 0, sizeof(dp));
    dp[1][0][0] = (john[0] > paul[0]);
    for (int i = 1; i < n; ++i) {
        dp[1][i][0] = dp[1][i - 1][0] + (john[i] > paul[0]);
        dp[1][i][0] %= MOD;
    }

    for (int j = 1; j < m; ++j) {
        dp[1][0][j] = dp[1][0][j - 1] + (john[0] > paul[j]);
        dp[1][0][j] %= MOD;
    }

    for (int i = 1; i < n; ++i) {
        int num_beat = (john[i] > paul[0]);

        for (int j = 1; j < m; ++j) {
            num_beat += (john[i] > paul[j]);
            dp[1][i][j] = dp[1][i - 1][j] + num_beat;
            dp[1][i][j] %= MOD;
        }
    }

    for (int k = 2; k <= max_team_size; ++k) {
        for (int i = k - 1; i < n; ++i) {
            for (int j = k - 1; j < m; ++j) {
                dp[k][i][j] += dp[k][i - 1][j];
                dp[k][i][j] %= MOD;
                dp[k][i][j] += dp[k][i][j - 1];
                dp[k][i][j] %= MOD;

                dp[k][i][j] -= dp[k][i - 1][j - 1];
                while (dp[k][i][j] < 0) {
                    dp[k][i][j] += MOD;
                }
                dp[k][i][j] %= MOD;

                if (i > 0 and j > 0 and john[i] > paul[j]) {
                    dp[k][i][j] += dp[k - 1][i - 1][j - 1];
                    dp[k][i][j] %= MOD;
                }
            }
        }
    }

    /*
    for (int k = 1; k <= max_team_size; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << dp[k][i][j] << ' ';
            }
            cout << '\n';
        }

        cout << '\n';
    }
    */

    fout << dp[max_team_size][n - 1][m - 1] << '\n';

    return 0;
}
