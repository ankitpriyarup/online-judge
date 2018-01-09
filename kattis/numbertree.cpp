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

int h;
char path[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %s", &h, path);
    ll total = (1LL << (h + 1LL));
    int node = 1;
    for (char* s = path; *s != '\0'; ++s) {
        node <<= 1;
        if (*s == 'R')
            node |= 1;
    }

    printf("%lld\n", total - node);

    return 0;
}
