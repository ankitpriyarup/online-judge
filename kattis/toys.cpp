#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, k;
    scanf("%d %d", &n, &k);

    // f(n, k) = (f(n - 1, k) + k) % n
    //         = (((f(n - 2, k) + k) % (n - 1)) + k) % n
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = (ans + k) % i;
    }

    printf("%d\n", ans);

    return 0;
}
