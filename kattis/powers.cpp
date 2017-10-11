#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    scanf("%d %d", &a, &b);
    if (a % 2 == 1) {
        printf("%d\n", 0);
    } else {
        int base = a / 2;
        int res = 1;
        for (int i = 0; i < b; ++i) {
            res = (1LL * base * res) % a;
        }

        printf("%d\n", res);
    }
    
    return 0;
}
