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

    int n, q;
    scanf(" %d %d", &n, &q);
    --q;
    int buf = 0;
    while (n > 1) {
        int k = n / 2;
        if (q < k) {
            buf += n - k;
            n = k;
        } else {
            n -= k;
            q -= k;
        }
        q = n - 1 - q;
    }

    printf("%d\n", q + buf + 1);
    
    return 0;
}
