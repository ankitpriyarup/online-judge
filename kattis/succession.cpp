#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
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

    int n, m;
    cin >> n >> m;
    string founder;
    cin >> founder;
    string ch, p0, p1;
    map<string, vector<string>> graph;
    map<string, int> in_deg;
    for (int i = 0; i < n; ++i) {
        cin >> ch >> p0 >> p1;
        graph[p0].push_back(ch);
        graph[p1].push_back(ch);
        in_deg[ch] += 2;
        in_deg[p0] += 0;
        in_deg[p1] += 0;
    }

    queue<string> q;
    for (auto it : in_deg) {
        if (it.second == 0) {
            q.push(it.first);
        }
    }

    map<string, double> royalty;
    royalty[founder] = 1.0;
    while (!q.empty()) {
        string s = q.front();
        q.pop();

        for (string child : graph[s]) {
            royalty[child] += royalty[s] / 2.0;

            if (--in_deg[child] == 0) {
                q.push(child);
            }
        }
    }

    string ans = "";
    double best = 0.0;
    while (m-- > 0) {
        cin >> ch;
        if (royalty[ch] > best) {
            ans = ch;
            best = royalty[ch];
        }
    }

    cout << ans << '\n';
    
    return 0;
}
