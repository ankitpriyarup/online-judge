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

char s[200005], t[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %s", s);
    scanf(" %s", t);

    int a = 0;
    int b = 0;
    int n = strlen(s);
    int m = strlen(t);

    reverse(s, s + n);
    reverse(t, t + m);

    while (a < n and b < m and s[a] == t[b]) {
        ++a;
        ++b;
    }

    int ans = n - a + m - b;
    printf("%d\n", ans);
    
    return 0;
}
