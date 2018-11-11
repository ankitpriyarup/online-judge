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

int count(const vector<int>& a, int up) {
    int n = a.size();
    int peaks = 0;
    for (int i = 0; i < n; ++i) {
        // check peak
        bool is_peak = true;
        for (int j = i - up + 2; j <= i; ++j) {
            if (j < 1 or j >= n) {
                is_peak = false;
                break;
            }
            is_peak &= a[j] > a[j - 1];
        }

        for (int j = i + 1; j <= i + up - 1; ++j) {
            if (j < 1 or j >= n) {
                is_peak = false;
                break;
            }
            is_peak &= a[j] < a[j - 1];
        }

        if (is_peak)
            ++peaks;
    }

    return peaks;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, up, down;
    cin >> n >> up >> down;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int peaks = count(a, up);
    for (int i = 0; i < n; ++i)
        a[i] = -a[i];
    int valleys = count(a, down);

    cout << peaks << ' ' << valleys;
    return 0;
}
