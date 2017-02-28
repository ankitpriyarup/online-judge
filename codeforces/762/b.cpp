#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int m;
vector<pair<int, int> > mice;

int main() {
    int a, b, both;
    cin >> a >> b >> both;

    cin >> m;

    int cost;
    string type;
    for (int i = 0; i < m; ++i) {
        cin >> cost >> type;
        mice.push_back(make_pair(cost, type[0] == 'P'));
    }

    sort(mice.begin(), mice.end());

    bool isPS2;
    int sat = 0;
    long long tot_cost = 0LL;
    for (int i = 0; i < m; ++i) {
        cost = mice[i].first;
        isPS2 = mice[i].second;

        if (!isPS2 and a > 0) {
            ++sat;
            tot_cost += cost;
            --a;
        } else if (isPS2 and b > 0) {
            ++sat;
            tot_cost += cost;
            --b;
        } else if (both > 0) {
            ++sat;
            tot_cost += cost;
            --both;
        }
    }

    cout << sat << ' ' << tot_cost << '\n';
    return 0;
}
