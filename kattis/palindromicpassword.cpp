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

inline int flip(int x) {
    int a = x / 100;
    int b = (x / 10) % 10;
    int c = x % 10;
    return 100 * c + 10 * b + a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    set<int> s;
    for (int i = 100; i < 1000; ++i) {
        s.insert(1000 * i + flip(i));
    }

    int q;
    scanf("%d", &q);
    int x;
    while (q-- > 0) {
        scanf("%d", &x);
        auto it = s.lower_bound(x);
        if (it != begin(s) and x - *prev(it) <= *it - x)
            it = prev(it);

        printf("%d\n", *it);
    }
    
    return 0;
}
