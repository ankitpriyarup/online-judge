#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int num_minions;
    cin >> num_minions;

    vector<pair<int, int> > minions;
    int l, u;

    for (int i = 0; i < num_minions; ++i) {
        cin >> l >> u;
        minions.push_back(make_pair(l, u));
    }

    sort(minions.begin(), minions.end(), [](const pair<int, int> a, const pair<int, int> b) -> bool {
            return a.second < b.second;
        });

    int index = 0;
    int rooms = 0;

    while (index < num_minions) {
        int temp = minions[index].second;
        ++rooms;
        while (index < num_minions and minions[index].first <= temp and temp <= minions[index].second) {
            ++index;
        }
    }

    cout << rooms << '\n';

    return 0;
}
