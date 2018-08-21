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

string a, b;
int occ;

constexpr int C = 1289753;
constexpr int M = 1e9 + 7;

int sum(int a, int b, int mod=M) {
    int c = a + b;
    if (c >= mod) {
        c -= mod;
    }

    return c;
}

int prod(int a, int b, int mod=M) {
    return 1LL * a * b % mod;
}

bool works(int len) {
    int val = 0;
    int exp = 0;
    int pw = 1;
    for (int i = 0; i < len; ++i) {
        val = sum(prod(val, C), a[i]);
        exp = sum(prod(exp, C), b[i]);
        pw = prod(pw, C);
    }

    int n = a.size();
    int found = 0;
    // printf("len %d\n", len);
    for (int i = len; i <= n; ++i) {
        if (val == exp) {
            // printf("match at [%d, %d)\n", i - len, i);
            ++found;
        }

        if (i == n) break;

        val = sum(prod(val, C), a[i]);
        int sub = M - prod(pw, a[i - len]);
        val = sum(val, sub);
    }

    return found >= occ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    getline(cin, a);
    getline(cin, b);
    cin >> occ;

    int lo = 1;
    int hi = b.size() + 1;
    if (!works(lo)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (works(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << b.substr(0, lo) << '\n';

    return 0;
}
