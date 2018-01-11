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

    int a, b, c;
    while (T-- > 0) {
        scanf("%d %d %d", &a, &b, &c);
        if (a < b and a < c) {
            printf("First\n");
        } else if (b < a and b < c) {
            printf("Second\n");
        } else {
            printf("Third\n");
        }
    }

    return 0;
}
