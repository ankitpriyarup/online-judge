#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

using ll = long long;

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", a + b - 1);
    }
    return 0;
}
