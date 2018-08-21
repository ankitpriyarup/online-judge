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

constexpr int MAXV = 1e6 + 666;
int phi[MAXV];

void gen_phi() {
    for (int i = 0; i < MAXV; ++i)
        phi[i] = i & 1 ? i : i / 2;
    for (int i = 3; i < MAXV; i += 2)
        if (phi[i] == i)
            for (int j = i; j < MAXV; j += i)
                (phi[j] /= i) *= i - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_phi();

    int T;
    scanf(" %d", &T);
    int m;
    while (T-- > 0) {
        scanf(" %d", &m);
        printf("%lld\n", 1LL * phi[m] * (m - 1LL));
    }
    
    return 0;
}
