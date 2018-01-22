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

constexpr int MAXN = 111;
int n;
char s[MAXN], t[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    int r = 1;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0)
            r = i;
    }

    int x = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = i; j < n; j += r)
            t[x++] = s[j];
    }

    printf("%s\n", t);

    return 0;
}
