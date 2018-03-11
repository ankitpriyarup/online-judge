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

/*
 * @author panks
 * Big Integer library in C++, single file implementation.
 */
#define MAX 1000006 // for strings

static pair<string, long long> divide(string n, long long den) {
    long long rem = 0;
    string result;
    result.resize(MAX);

    for (int indx = 0, len = n.length(); indx < len; ++indx) {
        rem = (rem * 10) + (n[indx] - '0');
        result[indx] = rem / den + '0';
        rem %= den;
    }

    result.resize(n.length());

    while (result[0] == '0' && result.length() != 1)
        result.erase(0, 1);

    if (result.length() == 0)
        result = "0";

    return make_pair(result, rem);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    if (s.size() == 1) {
        cout << s << '\n';
        return 0;
    }

    int sz = s.size();

    for (int d = 0; d > -10; --d) {
        if (sz + d <= 1) break;

        auto res = divide(s, sz + d);
        if (res.second == 0) {
            if (res.first.size() == sz + d) {
                cout << res.first << '\n';
                break;
            }
        }
    }

    return 0;
}
