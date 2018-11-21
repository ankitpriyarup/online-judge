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

int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int valid(int d, int m, int y) {
    if (y < 2000)
        return 0;

    int leap = y % 4 == 0 and (y % 100 != 0 or y % 400 == 0);
    if (m < 1 or m > 12)
        return 0;

    int exp = days[m];
    if (m == 2 and leap)
        ++exp;

    return 1 <= d and d <= exp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        char d[10], m[10], y[10];
        scanf(" %s %s %s", d, m, y);
        vector<int> digits;
        for (int i = 0; i < 2; ++i)
            digits.push_back(d[i] - '0');
        for (int i = 0; i < 2; ++i)
            digits.push_back(m[i] - '0');
        for (int i = 0; i < 4; ++i)
            digits.push_back(y[i] - '0');
        sort(begin(digits), end(digits));

        vector<int> opts;
        do {
            int day = 10 * digits[0] + digits[1];
            int month = 10 * digits[2] + digits[3];
            int year = 1000 * digits[4] + 100 * digits[5] + 10 * digits[6] + digits[7];
            if (valid(day, month, year)) {
                opts.push_back(10000 * year + 100 * month + day);
            }
        } while (next_permutation(begin(digits), end(digits)));

        sort(begin(opts), end(opts));
        opts.erase(unique(begin(opts), end(opts)), end(opts));

        if (opts.empty()) {
            printf("%d\n", 0);
        } else {
            int day = opts[0] % 100;
            int month = (opts[0] / 100) % 100;
            int year = opts[0] / 10000;

            printf("%d %02d %02d %04d\n", (int)opts.size(), day, month, year);
        }
    }
    
    return 0;
}
