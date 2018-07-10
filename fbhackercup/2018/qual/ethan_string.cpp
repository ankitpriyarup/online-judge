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

bool ethan_contain(const string& a, const string& b) {
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    while (i < n and j < m) {
        if (a[i] == b[j]) {
            ++i;
            ++j;
        } else if (i == 0) {
            ++j;
        } else {
            i = 0;
        }
    }

    if (i >= n) return true;
    return false;
}

string solve() {
    string s;
    cin >> s;

    int n = s.size();
    for (int p = 1; p < n; ++p) {
        string t;
        for (int i = 0; i < p; ++i) {
            t.push_back(s[i]);
        }
        t += s;

        if (!ethan_contain(s, t)) {
            return t;
        }
    }

    return "Impossible";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": " << solve() << '\n';
    }

    return 0;
}
