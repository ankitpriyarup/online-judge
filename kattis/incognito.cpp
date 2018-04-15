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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        string a, b;
        map<string, vector<string>> kinds;
        for (int i = 0; i < n; ++i) {
            cin >> a >> b;
            kinds[b].push_back(a);
        }

        ll res = 1;
        for (auto& p : kinds) {
            res *= p.second.size() + 1LL;
        }

        printf("%lld\n", res - 1);
    }
    
    return 0;
}
