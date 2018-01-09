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

string cards[15];

bool valid(const char& a, const char& b, const char& c) {
    return (a == b and b == c) or (a != b and b != c and a != c);
}

bool is_set(const string& a, const string& b, const string& c) {
    for (int i = 0; i < 4; ++i) {
        if (!valid(a[i], b[i], c[i]))
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 12; ++i) {
        cin >> cards[i];
    }

    bool found_set = false;
    for (int i = 1; i <= 12; ++i) {
        for (int j = i + 1; j <= 12; ++j) {
            for (int k = j + 1; k <= 12; ++k) {
                if (is_set(cards[i], cards[j], cards[k])) {
                    found_set = true;
                    cout << i << ' ' << j << ' ' << k << '\n';
                }
            }
        }
    }

    if (!found_set)
        cout << "no sets\n";

    return 0;
}
