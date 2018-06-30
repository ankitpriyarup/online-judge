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
using clause = pair<vector<int>, vector<int>>;

bool works(int mask, const clause& c) {
    for (int x : c.first) {
        if ((mask & (1 << x)) == 0)
            return true;
    }
    for (int x : c.second) {
        if ((mask & (1 << x)) != 0)
            return true;
    }
    return false;
}

bool works(int mask, const vector<clause>& clauses) {
    for (const auto& c : clauses) {
        if (!works(mask, c)) {
            return false;
        }
    }

    return true;
}

bool valid(int n, const vector<clause>& clauses) {
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (works(mask, clauses))
            return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n, m;
        cin >> n >> m;

        string line_str, var;
        vector<clause> clauses(m);
        getline(cin, line_str);
        for (int i = 0; i < m; ++i) {
            getline(cin, line_str);

            // cout << "raw: " << line_str << '\n';
            // cout << "Clause " << i << ": ";
            istringstream iss(line_str);
            while (iss >> var) {
                int start = 1 + (var[0] == '~');
                int idx = stoi(var.substr(start)) - 1;

                if (var[0] == '~') {
                    // cout << " neg " << idx << " ";
                    clauses[i].first.push_back(idx);
                } else {
                    // cout << " pos " << idx << " ";
                    clauses[i].second.push_back(idx);
                }

                iss >> var;
            }

            // cout << '\n';
        }

        cout << (valid(n, clauses) ? "" : "un") << "satisfiable\n";
    }

    return 0;
}
