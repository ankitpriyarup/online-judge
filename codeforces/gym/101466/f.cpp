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

    int n;
    scanf(" %d", &n);
    bool valid = true;

    int a[3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j)
            scanf(" %d", &a[j]);
        sort(a, a + 3);
        if (a[0] + a[1] <= a[2])
            valid = false;
    }

    printf("%s\n", valid ? "YES" : "NO");
    
    return 0;
}
