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

    int T;
    cin >> T;
    int n;
    string start, s;
    while (T-- > 0) {
        cin >> n >> start;
        cin >> s;
        vector<int> starts;
        for (int i = 0; i < n; ++i) {
            if (s[i] == start[0])
                starts.push_back(i);
        }

        assert(starts.size());
        if (starts.size() == 1) {
            cout << 0 << '\n';
            continue;
        }

        int lo = 0;
        int hi = n;
        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;
            set<string> lefts, rights;
            // cout << "mid " << mid << '\n';

            int left_goal = 0;
            int right_goal = 0;
            for (int x : starts) {
                if (x - mid >= 0) {
                    ++left_goal;
                    string left = s.substr(x - mid, mid + 1);
                    // cout << "left " << left << '\n';
                    lefts.insert(left);
                }
                if (x + mid + 1 <= n) {
                    ++right_goal;
                    string right = s.substr(x, mid + 1);
                    // cout << "right " << right << '\n';
                    rights.insert(right);
                }
            }

            if (lefts.size() == left_goal or rights.size() == right_goal) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        cout << hi << '\n';
    }
    
    return 0;
}
