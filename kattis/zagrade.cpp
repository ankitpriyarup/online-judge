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

    string s;
    cin >> s;

    int n = s.size();
    vector<pii> pairs;
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stk.push_back(i);
        } else if (s[i] == ')') {
            pairs.emplace_back(stk.back(), i);
            stk.pop_back();
        }
    }

    int m = pairs.size();
    vector<string> ans;

    for (int mask = 1; mask < (1 << m); ++mask) {
        string t;
        vector<int> skip;
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                skip.push_back(pairs[i].first);
                skip.push_back(pairs[i].second);
            }
        }

        sort(begin(skip), end(skip));
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (p < skip.size() and skip[p] == i) {
                ++p;
            } else {
                t.push_back(s[i]);
            }
        }

        ans.push_back(t);
    }

    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    for (const string& t : ans) {
        cout << t << '\n';
    }
    return 0;
}
