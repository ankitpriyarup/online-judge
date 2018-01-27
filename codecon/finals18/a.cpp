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

int m;
constexpr int MAXN = 50;
string s[MAXN];
int p[MAXN];

int main() {
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s[i] >> p[i];
    }

    int n;
    cin >> n;
    bool first = true;
    int pass, drivers;
    for (int i = 0; i < n; ++i) {
        cin >> pass >> drivers;
        if (!first)
            cout << ' ';
        if (pass <= drivers) {
            cout << "1.0";
        } else {
            for (int j = 0; j < m; ++j) {
                int cur_pass = static_cast<int>(0.999 + pass * p[j] / 100.0);
                if (cur_pass <= drivers) {
                    cout << s[j];
                    break;
                }
            }
        }

        first = false;
    }
    cout << '\n';
    
    return 0;
}
