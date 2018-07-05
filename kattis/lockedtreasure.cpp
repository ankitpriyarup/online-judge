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

using ll = unsigned long long;
using ld = long double;
using pii = pair<int, int>;

ll choose[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    choose[0][0] = 1ULL;
    for (int i = 1; i <= 30; ++i) {
        choose[i][0] = choose[i][i] = 1ULL;
        for (int j = 1; j < i; ++j) {
            choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j];
        }
    }

    int T;
    scanf(" %d", &T);
    int n, m;
    while (T-- > 0) {
        scanf(" %d %d", &n, &m);
        printf("%llu\n", choose[n][m - 1]);
    }

    return 0;
}
