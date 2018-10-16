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

    int n;
    string s;
    cin >> n;
    cin >> s;
    s = "R" + s;

    vector<int> res;
    while (!s.empty()) {
        if (s.back() == 'R') {
            res.push_back(n--);
            s.pop_back();
        } else {
            int ct = 0;
            while (!s.empty() and s.back() == 'L') {
                ++ct;
                s.pop_back();
            }
            s.pop_back();
            for (int j = n - ct; j <= n; ++j) {
                res.push_back(j);
            }
            n = n - ct - 1;
        }
    }

    while (n > 0) {
        res.push_back(n--);
    }

    while (!res.empty()) {
        cout << res.back() << '\n';
        res.pop_back();
    }

    return 0;
}
