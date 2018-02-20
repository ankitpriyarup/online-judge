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

int n;
ll a[3], b[3], ans[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    int v;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v);
        a[i % 3] += v;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v);
        b[i % 3] += v;
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ans[(i + j) % 3] += a[i] * b[j];
        }
    }
   
    printf("%lld %lld %lld\n", ans[1], ans[2], ans[0]);
    return 0;
}
