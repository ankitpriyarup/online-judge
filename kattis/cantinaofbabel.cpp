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

constexpr int MAXN = 103;
int n;
vector<int> graph[MAXN];
string speaks[MAXN];
vector<string> hears[MAXN];

vector<int> val, comp, z, cont;
int timer = 0, ncomps;
int ans = 0;

int dfs(int u) {
    int low = val[u] = timer++;
    int x;
    z.push_back(u);
    for (const int& v : graph[u]) {
        if (comp[v] < 0) {
            low = min(low, val[v] ? val[v] : dfs(v));
        }
    }

    if (low == val[u]) {
        do {
            x = z.back();
            z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != u);
        ans = max(ans, static_cast<int>(cont.size()));
        cont.clear();
        ++ncomps;
    }

    return val[u] = low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);
    istringstream iss(s);
    iss >> n;

    string name, hear;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        istringstream iss(s);
        iss >> name >> speaks[i];
        while (iss >> hear) {
            hears[i].push_back(hear);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (speaks[j] == speaks[i]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
                // printf("Edge from %d to %d\n", i, j);
                // printf("Edge from %d to %d\n", j, i);
                continue;
            }

            for (const string& hear : hears[j]) {
                if (speaks[i] == hear) {
                    graph[i].push_back(j);
                    // printf("Edge from %d to %d\n", i, j);
                    break;
                }
            }

            for (const string& hear : hears[i]) {
                if (speaks[j] == hear) {
                    graph[j].push_back(i);
                    // printf("Edge from %d to %d\n", j, i);
                    break;
                }
            }
        }
    }

    val.assign(n, 0);
    comp.assign(n, -1);
    timer = ncomps = 0;
    for (int i = 0; i < n; ++i) {
        if (comp[i] < 0)
            dfs(i);
    }

    cout << (n - ans) << endl;

    return 0;
}
