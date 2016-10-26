#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int n;
struct team {
    long long rank;
    long long cost;
    team(long long rank, long long cost): rank(rank), cost(cost) {};
};
 
bool cmp(const team& me, const team& other) {
    if (me.rank == other.rank) {
        return me.cost < other.cost;
    }
    return me.rank < other.rank;
}

class Comp2 {
public:
    bool operator() (const team& me, const team& other) {
        return other.cost < me.cost;
    }
};

int main() {
    cin >> n;
    long long mt, mw, t, w;
    cin >> mt >> mw;

    vector<team> teams;
    priority_queue<team, vector<team>, Comp2> better_teams;

    for (int i = 0; i < n - 1; ++i) {
        cin >> t >> w;
        teams.push_back(team(t, w - t + 1));
        if (t > mt) {
            better_teams.push(teams[i]);
        }
    }

    int ranking = better_teams.size();
    sort(teams.begin(), teams.end(), cmp);
    int ptr = n - 2;
    while (ptr >= 0 and teams[ptr].rank > mt) {
        --ptr;
    }

    int dq = 0;
    //cout << "Current ranking: " << ranking << '\n';
    while (!better_teams.empty()) {
        team top = better_teams.top();
        better_teams.pop();

        long long cost = top.cost;
        if (mt >= cost) {
            //cout << "DQ: " << top.rank << '\n';
            mt -= cost;
            ++dq;
            while (ptr >= 0 and teams[ptr].rank > mt) {
                better_teams.push(teams[ptr]);
                --ptr;
            }
            //cout << "Current balloons: " << mt << '\n';
            //cout << "Current ranking: " << (n - ptr - 2 - dq) << '\n';
            ranking = min(ranking, n - ptr - 2 - dq);
        } else {
            break;
        }
    }

    cout << (ranking + 1) << '\n';
    return 0;
}
