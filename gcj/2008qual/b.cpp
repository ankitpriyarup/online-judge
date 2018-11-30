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

int parse(const string& ts) {
    int h = (ts[0] - '0') * 10 + (ts[1] - '0');
    int m = (ts[3] - '0') * 10 + (ts[4] - '0');

    return 60 * h + m;
}

using event = tuple<int, int, int>;

void solve() {
    int turnaround;
    cin >> turnaround;
    int n, m;
    cin >> n >> m;
    string ts;
    vector<event> events;
    for (int i = 0; i < n; ++i) {
        cin >> ts;
        int x = parse(ts);
        cin >> ts;
        int y = parse(ts);
        events.push_back({x, y, 0});
    }
    for (int i = 0; i < m; ++i) {
        cin >> ts;
        int x = parse(ts);
        cin >> ts;
        int y = parse(ts);
        events.push_back({x, y, 1});
    }

    sort(begin(events), end(events));

    int ansA = 0;
    int ansB = 0;

    multiset<int> msA, msB;
    int x, t, y;
    for (auto& evt : events) {
        tie(x, y, t) = evt;
        if (t == 0) {
            if (msA.empty() or *begin(msA) > x) {
                ++ansA;
            } else {
                msA.erase(begin(msA));
            }

            msB.insert(y + turnaround);
        } else {
            if (msB.empty() or *begin(msB) > x) {
                ++ansB;
            } else {
                msB.erase(begin(msB));
            }

            msA.insert(y + turnaround);
        }
    }

    cout << ansA << ' ' <<  ansB << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    int T;
    cin >> T;
    while (T-- > 0) {
        cout << "Case #" << tc++ << ": ";
        solve();
    }

    return 0;
}
