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

bool seen[500];
int occ[5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    int trans[300];
    trans['P'] = 0;
    trans['K'] = 1;
    trans['H'] = 2;
    trans['T'] = 3;

    for (int i = 0; i < 4; ++i)
        occ[i] = 13;

    int n = s.size();
    for (int i = 0; i < n; i += 3) {
        int suit = trans[s[i]];
        int card = 10 * (s[i + 1] - '0') + s[i + 2] - '0' - 1;
        if (seen[4 * card + suit]) {
            cout << "GRESKA";
            return 0;
        }

        seen[4 * card + suit] = true;
        --occ[suit];
    }

    for (int i = 0; i < 4; ++i)
        printf("%d ", occ[i]);
    
    return 0;
}
