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

void trouble(vector<int>& a) {
    int n = a.size();
    bool change = true;

    while (change) {
        change = false;
        for (int i = 0; i + 2 < n; ++i) {
            if (a[i] > a[i + 2]) {
                change = true;
                swap(a[i], a[i + 2]);
            }
        }
    }
}

void trouble_fast(vector<int>& a) {
    int n = a.size();
    vector<int> evens, odds;
    for (int i = 0; i < n; ++i) {
        (i & 1 ? odds : evens).push_back(a[i]);
    }
    sort(begin(evens), end(evens));
    sort(begin(odds), end(odds));
    for (int i = 0; i < n; ++i) {
        a[i] = (i & 1) ? odds[i / 2] : evens[i / 2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tc = 1;
    int T;
    cin >> T;
    int n;
    while (T-- > 0) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> b(begin(a), end(a));
        sort(begin(b), end(b));
        trouble_fast(a);

        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                found = true;
                cout << "Case #" << tc++ << ": " << i << '\n';
                break;
            }
        }

        if (!found)
            cout << "Case #" << tc++ << ": " << "OK" << '\n';
    }

    return 0;
}
