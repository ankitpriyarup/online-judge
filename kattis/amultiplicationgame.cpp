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

string names[] = {"Stan", "Ollie"};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    // stan wins games [0, 9]
    // ollie wins games [10, 18]
    // stan wins games [19, 162]
    //
    // stan wins [0, 9]
    // ollie wins [9 + 1, 9 * 2]
    // stan wins [9 * 2 + 1, 9 * 2 * 9]
    while (cin >> n) {
        ll val = 9;
        int winner = 0;

        while (val < n) {
            if (winner == 0) {
                val *= 2LL;
            } else {
                val *= 9LL;
            }

            winner ^= 1;
        }

        cout << names[winner] << " wins.\n";
    }
    
    return 0;
}
