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

    int n, q;
    cin >> n >> q;
    vector<int> dates;
    dates.push_back(0);
    vector<string> names;
    names.push_back("Aegon");

    string s;
    int d;
    for (int i = 0; i < n; ++i) {
        cin >> s >> d;
        dates.push_back(d);
        names.push_back(s);
    }

    /*
    for (int i = 0; i <= n; ++i) {
        cout << dates[i] << ' ' << names[i] << '\n';
    }

    cout << '\n';
    */

    int x;
    while (q-- > 0) {
        cin >> x;
        int idx = upper_bound(begin(dates), end(dates), x) - begin(dates) - 1;
        // cout << x << ": " << idx << ' ' << dates[idx] << ' ' << names[idx] << '\n';
        cout << names[idx] << '\n';
    }

    return 0;
}
