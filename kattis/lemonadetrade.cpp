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
using ld = long double;
using pii = pair<int, int>;

constexpr ld INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    map<string, ld> of_kind;
    of_kind["pink"] = 0.0L;
    string src, dst;
    ld ratio;
    while (n-- > 0) {
        cin >> dst >> src >> ratio;
        ratio = log(ratio);

        if (of_kind.find(src) != end(of_kind)) {
            ld res = of_kind.find(dst) == end(of_kind) ? -INF : of_kind[dst];
            res = max(res, ratio + of_kind[src]);

            of_kind[dst] = res;
        }
    }

    if (of_kind.find("blue") == end(of_kind)) {
        printf("%.17Lf\n", 0.0L);
    } else {
        ld ans = min(log(10.0L), of_kind["blue"]);
        printf("%.17Lf\n", exp(ans));
    }
    
    return 0;
}
