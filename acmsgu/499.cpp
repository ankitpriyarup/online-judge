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

constexpr int MAXN = 1e5 + 5;
constexpr int MAXV = 1e6 + 66;
int n;
int freq[MAXV];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &x);
        ++freq[x];
    }

    int ans = 1;
    for (int i = 2; i < MAXV; ++i) {
        int tot_occ = 0;
        for (int j = i; j < MAXV; j += i) {
            tot_occ += freq[j];
        }
        if (tot_occ >= 2)
            ans = i;
    }

    printf("%d\n", ans);

    return 0;
}
