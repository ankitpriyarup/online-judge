#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

int num_planets;
vector<int> tree[50004];
int populations[50004];

int main() {
    int num_cases;
    cin >> num_cases;

    while (num_cases-- > 0) {
        cin >> num_planets;

        set<pair<int, int> > safe;
        safe.insert(make_pair(0, 0));

        for (int i = 1; i <= num_planets; ++i) {
            tree[i].clear();
            cin >> populations[i];
            safe.insert(make_pair(populations[i], i));
        }

        int u, v;
        for (int i = 0; i < num_planets - 1; ++i) {
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }


        for (int i = 1; i <= num_planets; ++i) {
            set<int> dangerous(tree[i].begin(), tree[i].end());
            dangerous.insert(i);

            auto ptr = prev(safe.end());
            while (dangerous.find(ptr->second) != dangerous.end()) {
                ptr = prev(ptr);
            }

            cout << ptr->second << ' ';
        }

        cout << '\n';
    }

    return 0;
}
