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

    int l, r;
    scanf(" %d %d", &l, &r);
    if (l == 0 and r == 0) {
        printf("Not a moose\n");
    } else if (l == r) {
        printf("Even %d\n", 2 * l);
    } else {
        printf("Odd %d\n", 2 * max(l, r));
    }
    
    return 0;
}
