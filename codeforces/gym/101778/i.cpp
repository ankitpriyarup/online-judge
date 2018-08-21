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

    int T;
    scanf(" %d", &T);
    int a, b, c, d;
    while (T-- > 0) {
        scanf(" %d %d %d %d", &a, &b, &c, &d);
        pii s1 = make_pair(a + c, c);
        pii s2 = make_pair(b + d, b);
        if (s1 > s2) {
            printf("%d\n", 1);
        } else if (s1 < s2) {
            printf("%d\n", 2);
        } else {
            printf("%d\n", -1);
        }
    }
    
    return 0;
}
