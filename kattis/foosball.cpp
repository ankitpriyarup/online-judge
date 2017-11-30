#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    // 0 - white, 1 - black
    // 0 - offense, 1 - defense
    string players[2][2];
    cin >> n;
    cin >> players[0][0] >> players[1][0] >> players[0][1] >> players[1][1];
    deque<string> reserve;
    string s;
    for (int i = 5; i <= n; ++i) {
        cin >> s;
        reserve.push_back(s);
    }

    string record;
    cin >> record;

    int best_streak = 0;
    int cur_streak = 0;
    vector<pair<string, string> > best_teams;

    int prev_winner = -1;
    int m = record.size();
    bool in_prefix = true;

    for (int i = 0; i < m; ++i) {
        /*
        cout << "Streak: " << cur_streak << '\n';
        cout << players[0][0] << " and " << players[0][1] << " vs " << players[1][0] << " and " << players[1][1] << '\n';
        cout << "Reserve: ";
        for (string x : reserve) {
            cout << x << " ";
        } cout << '\n';
        */

        int c = record[i] == 'B';
        if (c != prev_winner) {
            // handle streak updates
            if (cur_streak > best_streak) {
                best_streak = cur_streak;
                best_teams.clear();
            }

            if (prev_winner != -1 and cur_streak == best_streak) {
                int ind = in_prefix ? (cur_streak % 2) : 1 - (cur_streak % 2);
                best_teams.push_back({players[prev_winner][ind], players[prev_winner][1 - ind]});
            }

            cur_streak = 1;
            if (prev_winner != -1) in_prefix = false;
        } else {
            ++cur_streak;
        }

        swap(players[c][0], players[c][1]);
        reserve.push_back(players[1 - c][1]);
        players[1 - c][1] = players[1 - c][0];
        players[1 - c][0] = reserve.front();
        reserve.pop_front();

        prev_winner = c;
    }

    // handle streak updates
    if (cur_streak > best_streak) {
        best_streak = cur_streak;
        best_teams.clear();
    }

    if (prev_winner != -1 and cur_streak == best_streak) {
        int ind = in_prefix ? (cur_streak % 2) : 1 - (cur_streak % 2);
        best_teams.push_back({players[prev_winner][ind], players[prev_winner][1 - ind]});
    }

    // cout << best_streak << '\n';
    for (auto res : best_teams) {
        cout << res.first << ' ' << res.second << '\n';
    }
    
    return 0;
}
