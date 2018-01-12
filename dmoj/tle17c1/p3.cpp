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

constexpr int MAXN = 100005;

int n, t;
char arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &t);
    scanf("%s", arr);

    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == '|') {
            ++total;
        }
    }

    int x;
    while (t-- > 0) {
        scanf("%d", &x);
        --x;
        if (arr[x] == '|') {
            arr[x] = '-';
            --total;
        } else {
            arr[x] = '|';
            ++total;
        }

        if (arr[0] == '|') {
            printf("%d\n", 1);
        } else {
            printf("%lld\n", 2LL * total + n);
        }
    }

    return 0;
}
