#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 50;
int n;
map<string, vector<string> > deps;
map<string, vector<string> > rev;
map<string, int> in_deg;

int main() {
    string res;
    cin >> res;

    cin >> n;

    string name, dep;
    vector<string> names;
    int qq;

    for (int i = 0; i < n; ++i) {
        cin >> name >> qq;
        names.push_back(name);

        in_deg[names[i]] = qq;
        while (qq-- > 0) {
            cin >> dep;
            deps[names[i]].push_back(dep);
            rev[dep].push_back(names[i]);
        }
    }

    set<string> s;
    queue<string> q;
    q.push(res);
    s.insert(res);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        for (string nx : deps[cur]) {
            q.push(nx);
            s.insert(nx);
        }
    }

    bool done = false;
    vector<string> order;

    while (!done) {
        vector<string> layer;
        for (int i = 0; i < n; ++i) {
            if (in_deg[names[i]] == 0 and s.find(names[i]) != end(s)) {
                if (names[i] == res) {
                    done = true;
                }
                layer.push_back(names[i]);
            }
        }

        for (auto name : layer) {
            in_deg[name] = -1;
            for (string nx : rev[name]) {
                --in_deg[nx];
            }
        }

        sort(begin(layer), end(layer));
        order.insert(end(order), begin(layer), end(layer));
    }

    for (auto x : order) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}
