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

    int a, b, c, x, y, z;
    scanf(" %d %d %d", &a, &b, &c);
    scanf(" %d %d %d", &x, &y, &z);

    int ans = min((a / x), (b / y));
    ans = min(ans, c / z);

    printf("%d\n", ans);
    
    return 0;
}
