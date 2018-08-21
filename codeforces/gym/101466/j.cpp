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

constexpr int MOD = 30000000;
int freq[MOD];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, q;
    scanf(" %d %d %d", &n, &m, &q);
    deque<int> window;
    int x;
    for (int i = 0; i < m; ++i) {
        scanf(" %d", &x);
        ++freq[x];
        window.push_back(x);
    }

    for (int i = m; i < n; ++i) {
        int c = window[0] + window[1];
        if (c >= MOD)
            c -= MOD;
        ++freq[c];
        window.push_back(c);
        window.pop_front();
    }

    for (int i = 1; i < MOD; ++i) {
        freq[i] += freq[i - 1];
    }

    int b;
    while (q-- > 0) {
        scanf(" %d", &b);
        --b;
        // find smallest x such that freq[x] > b
        int lo = -1;
        int hi = MOD - 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi + 1) >> 1;
            if (freq[mid] > b) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        printf("%d\n", hi);
    }

    return 0;
}
