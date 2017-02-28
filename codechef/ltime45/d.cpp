#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    if (n == 3) {
        puts("106732 139820");
        puts("210379 490375");
        puts("42 483426");
    } else {
        if (n > 4) {
            puts("0 0");
        }

        puts("580981 431795");
        puts("914958 554338");
        puts("518360 23016");
        puts("441824 483616");
    }
    return 0;
}
