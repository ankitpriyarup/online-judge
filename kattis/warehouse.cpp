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

void solve() {
    int n;
    cin >> n;
    map<string, int> freq;
    string name;
    int count;
    for (int i = 0; i < n; ++i) {
        cin >> name >> count;
        freq[name] += count;
    }

    vector<pair<int, string>> out;
    for (auto& p : freq) {
        out.emplace_back(-p.second, p.first);
    }
    sort(begin(out), end(out));
    cout << out.size() << '\n';
    for (auto& p : out) {
        cout << p.second << ' ' << (-p.first) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    
    return 0;
}
