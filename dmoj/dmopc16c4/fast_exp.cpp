#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    long long x;
    while (n-- > 0) {
        scanf("%lld", &x);

        if ((x & (x - 1)) == 0) {
            puts("T");
        } else {
            puts("F");
        }
    }
    return 0;
}
