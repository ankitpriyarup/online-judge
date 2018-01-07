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

int n, m;
map<string, int> vals;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m >> n;
    string s;
    int v;
    for (int i = 0; i < m; ++i) {
        cin >> s >> v;
        vals[s] = v;
    }

    for (int i = 0; i < n; ++i) {
        int score = 0;
        while (cin >> s) {
            if (s == ".")
                break;

            score += vals[s];
        }

        cout << score << '\n';
    }

    return 0;
}
