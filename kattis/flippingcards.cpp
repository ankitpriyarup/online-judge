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

/**
 * Ripped from KACTL, arnav-fied
 *
 * Negated variables are represented by bit inversions (~x).
 */
struct TwoSat {
    int vars;
    vector<vector<int>> graph;
    vector<int> values;

    TwoSat(int vars = 0): vars(vars), graph(2 * vars) {}

    int add_var() {
        graph.emplace_back();
        graph.emplace_back();
        return vars++;
    }

    void either(int a, int b) {
        auto conv = [](int x) {
            return x >= 0 ? (x << 1) : -2 * x - 1;
        };
        a = conv(a);
        b = conv(b);

        graph[a ^ 1].push_back(b);
        graph[b ^ 1].push_back(a);
    }

    // a = true
    void set_true(int a) {
        either(a, a);
    }

    // a -> b
    void implies(int a, int b) {
        either(~a, b);
    }

    // At most one of the m variables in block is true.
    // Creates m - 2 dummy variables.
    void at_most_one(const vector<int>& block) {
        if (block.size() <= 1)
            return;

        int cur = ~block[0];
        for (int i = 2; i < block.size(); ++i) {
            int y = add_var();
            either(cur, ~block[i]);
            either(cur, y);
            either(~block[i], y);
            cur = ~y;
        }

        either(cur, ~block[1]);
    }

    vector<int> val, comp, z;
    int time = 0;
    int dfs(int i) {
        int low = val[i] = ++time;
        z.push_back(i);
        for (auto& e : graph[i]) {
            if (!comp[e]) {
                low = min(low, val[e] ?: dfs(e));
            }
        }
        ++time;
        if (low == val[i]) {
            int x;
            do {
                x = z.back();
                z.pop_back();

                comp[x] = time;
                if (values[x >> 1] == -1) {
                    values[x >> 1] = !(x & 1);
                }
            } while (x != i);
        }

        return val[i] = low;
    }

    bool solve() {
        values.assign(vars, -1);
        val.assign(2 * vars, 0);
        comp = val;
        for (int i = 0; i < 2 * vars; ++i) {
            if (!comp[i]) {
                dfs(i);
            }
        }

        for (int i = 0; i < vars; ++i) {
            if (comp[2 * i] == comp[2 * i + 1]) {
                return 0;
            }
        }

        return 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        int n;
        scanf(" %d", &n);
        vector<vector<int>> by_val(2 * n + 1);
        int p, q;
        for (int i = 0; i < n; ++i) {
            scanf(" %d %d", &p, &q);
            by_val[p].push_back(i);
            by_val[q].push_back(~i);
        }

        TwoSat ts(n);
        for (const vector<int>& v : by_val) {
            ts.at_most_one(v);
        }

        printf("%s\n", ts.solve() ? "possible" : "impossible");
    }
    
    return 0;
}
