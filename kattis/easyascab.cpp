#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

constexpr int MAXN = 1003;
constexpr int SIGMA = 30;

string endchar;
int n;
string words[MAXN];

int nodes;
vector<int> graph[SIGMA];
int in_degree[SIGMA];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> endchar >> n;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    for (int i = 1; i < n; ++i) {
        int j = 0;
        while (j < words[i - 1].size() and j < words[i].size() and words[i][j] == words[i - 1][j]) {
            ++j;
        }
        if (j < words[i].size() and j < words[i - 1].size()) {
            graph[words[i - 1][j] - 'a'].push_back(words[i][j] - 'a');
            ++in_degree[words[i][j] - 'a'];
        } else {
            if (j >= words[i].size() and j < words[i - 1].size()) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    nodes = endchar[0] - 'a' + 1;
    queue<int> q;
    vector<int> output;
    for (int i = 0; i < nodes; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        if (q.size() > 1) {
            cout << "AMBIGUOUS\n";
            return 0;
        }
        int node = q.front();    
        q.pop();
        output.push_back(node);

        for (int x : graph[node]) {
            --in_degree[x];
            if (in_degree[x] == 0) {
                q.push(x);
            }
        }
    }

    if (output.size() != nodes) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (int x : output) {
        cout << ((char)('a' + x));
    }
    cout << '\n';

    return 0;
}
