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

constexpr int MAXN = 15;
int n, s, r;
int state[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d", &n, &s, &r);
    int x;
    for (int i = 0; i < s; ++i) {
        scanf("%d", &x);
        --state[x];
    }
    for (int i = 0; i < r; ++i) {
        scanf("%d", &x);
        ++state[x];
    }

    int bad = 0;
    for (int i = 1; i <= n; ++i) {
        if (state[i] == -1 and state[i + 1] == 1) {
            ++state[i];
            --state[i + 1];
        }

        if (state[i] == 1 and state[i + 1] == -1) {
            --state[i];
            ++state[i + 1];
        }

        if (state[i] == -1) {
            ++bad;
        }
    }

    printf("%d\n", bad);
    return 0;
}
