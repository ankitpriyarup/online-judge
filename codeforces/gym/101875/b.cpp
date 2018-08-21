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

int min_rot(const string& s) {
    int n = s.size();
    int a = 0;
    string ss = s + s;
    for (int b = 0; b < n; ++b) {
        for (int i = 0; i < n; ++i) {
            if (a + i == b or ss[a + i] < ss[b + i]) {
                b += max(0, i - 1);
                break;
            }
            if (ss[a + i] > ss[b + i]) {
                a = b;
                break;
            }
        }
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string s, t;
    cin >> n;
    cin >> s;

    t = s;
    rotate(t.begin(), t.begin() + min_rot(t), t.end());
    cout << (s == t ? "Yes" : "No") << '\n';
    
    return 0;
}
