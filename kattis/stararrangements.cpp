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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    printf("%d:\n", n);
    for (int i = 2; i < n; ++i) {
        if (n % (2 * i - 1) == 0 or n % (2 * i - 1) == i) {
            printf("%d,%d\n", i, i - 1);
        }
        if (n % i == 0) {
            printf("%d,%d\n", i, i);
        }
    }

    
    return 0;
}
