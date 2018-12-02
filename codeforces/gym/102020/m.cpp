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

    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(2, 0);
    for (int i = 0; i < n; ++i) {
        ++freq[s[i] - 'A'];
    }
    if (freq[0] % 2 == 1 or freq[1] % 2 == 1) {
        cout << "NO\n";
        return 0;
    }

    freq[0] >>= 1;
    freq[1] >>= 1;

    int half = n >> 1;
    vector<int> cur(2, 0);
    for (int i = 0; i < half; ++i) {
        ++cur[s[i] - 'A'];
    }
    if (freq == cur) {
        cout << "YES\n";
        cout << "1 " << (half + 1) << '\n';
        return 0;
    }

    for (int i = half; i < n; ++i) {
        --cur[s[i - half] - 'A'];
        ++cur[s[i] - 'A'];
        if (freq == cur) {
            int x = i - half + 2;
            cout << "YES\n";
            cout << x << " " << (x + half) << '\n';
            return 0;
        }
    }

    cout << "NO\n";
    
    return 0;
}
