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

constexpr int MAXN = 33;
constexpr int INF = 1e7;
int n;
vector<string> edges[MAXN];
int adj[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int p;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        for (int j = 0; j < p; ++j) {
            cin >> s;
            edges[i].push_back(s);
        }

        for (int j = 0; j < n; ++j)
            adj[i][j] = -1;

        adj[i][i] = 0;
    }

    bool changed = true;
    for (int iter = 0; changed and iter < n * n; ++iter) {
        changed = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                for (const string& s : edges[i]) {
                    bool poss = true;
                    int cost = 0;
                    for (const char& c : s) {
                        int k = c - 'a';
                        if (adj[k][j] == -1) {
                            poss = false;
                            break;
                        }

                        cost = max(cost, 1 + adj[k][j]);
                    }

                    if (poss) {
                        if (adj[i][j] == -1 or cost < adj[i][j]) {
                            changed = true;
                            adj[i][j] = cost;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
