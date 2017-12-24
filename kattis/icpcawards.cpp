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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<string, string> > winners;
    set<string> schools;
    string school, team;
    for (int i = 0; i < n; ++i) {
        cin >> school >> team;
        if (schools.find(school) != end(schools)) continue;
        schools.insert(school);
        winners.push_back({school, team});
    }

    for (int i = 0; i < 12; ++i) {
        cout << winners[i].first << ' ' << winners[i].second << '\n';
    }
    
    return 0;
}
