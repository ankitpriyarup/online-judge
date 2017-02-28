#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

vector<long long> parents(long long x) {
    vector<long long> result;
    while (x >= 1) {
        result.push_back(x);
        x >>= 1;
    }

    return result;
}

int main() {
    int q;
    cin >> q;

    int type;
    long long u, v, w;
    map<long long, long long> costs;

    while (q-- > 0) {
        cin >> type >> u >> v;
        vector<long long> u_parents = parents(u);
        vector<long long> v_parents = parents(v);

        while (!u_parents.empty() and !v_parents.empty() and u_parents.back() == v_parents.back()) {
            u_parents.pop_back();
            v_parents.pop_back();
        }

        if (type == 1) {
            cin >> w;
            for (long long up : u_parents) {
                costs[up] += w;
            }

            for (long long vp : v_parents) {
                costs[vp] += w;
            }
        } else {
            long long out = 0;
            for (long long up : u_parents) {
                out += costs[up];
            }

            for (long long vp : v_parents) {
                out += costs[vp];
            }

            cout << out << '\n';
        }
    }
    return 0;
}
