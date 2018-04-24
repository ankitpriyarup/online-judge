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
    if (n <= 8)
        printf("%d\n", 0);
    else if (n == 9)
        printf("%d\n", 8);
    else {
        char buf[(int)(1e6 + 666)];
        buf[0] = '7';
        buf[1] = '2';
        for (int i = 0; i < n - 10; ++i) {
            buf[i + 2] = '0';
        }
        buf[n - 10 + 2] = '\0';

        printf("%s\n", buf);
    }

    // 8 options for the last 9 digits
    // 9 options for the first digit
    // 10 options for the remaining n - 10 digits
    // 72 * 10^n - 10;
    
    return 0;
}
