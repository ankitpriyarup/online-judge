#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int n;
unordered_map<string, int> m[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    string s;
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            cin >> s;
            ++m[k][s];
        }
    }

    int ans = 0;
    for (auto val : m[0]) {
        ans += min(m[0][val.first], m[1][val.first]);
    }

    printf("%d\n", ans);
    
    return 0;
}
