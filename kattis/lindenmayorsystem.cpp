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

string rules[30];

int main() {
    int n, m;
    cin >> n >> m;

    string x, junk, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> junk >> y;
        rules[x[0] - 'A'] = y;
    }

    string s;
    cin >> s;
    for (int i = 0; i < m; ++i) {
        string t;
        for (int j = 0; j < s.size(); ++j) {
            if (rules[s[j] - 'A'].empty()) {
                t.push_back(s[j]);
            } else {
                t = t + rules[s[j] - 'A'];
            }
        }

        s = t;
    }

    cout << s << '\n';
    
    return 0;
}
