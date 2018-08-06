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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf(" %d %d", &n, &m);

    vector<pii> edges;
    for (int i = 2; i <= n; ++i) {
        edges.emplace_back(1, i);
    }

    m -= n - 1;

    for (int u = n; m > 0 and u > 1; --u) {
        for (int v = u - 1; m > 0 and v > 1; --v) {
            if (gcd(u, v) == 1) {
                edges.emplace_back(u, v);
                --m;
            }
        }
    }

    if (m != 0) {
        printf("Impossible\n");
    } else {
        printf("Possible\n");
        for (auto e : edges) {
            printf("%d %d\n", e.first, e.second);
        }
    }

    return 0;
}
