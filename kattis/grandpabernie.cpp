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
    cin >> n;
    map<string, vector<int>> trips;
    string s;
    int y;
    while (n-- > 0) {
        cin >> s >> y;
        trips[s].push_back(y);
    }

    for (auto it = begin(trips); it != end(trips); ++it) {
        sort(begin(it->second), end(it->second));
    }

    int m;
    cin >> m;
    while (m-- > 0) {
        cin >> s >> y;
        cout << trips[s][y - 1] << '\n';
    }
    
    return 0;
}
