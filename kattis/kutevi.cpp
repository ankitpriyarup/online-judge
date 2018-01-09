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

int n, k;
int a[15];
bool can_make[400];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &k);
    can_make[0] = true;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        for (int j = 0; j < 360; ++j) {
            if (!can_make[j]) continue;
            for (int dx = 0; dx <= 360; ++dx) {
                int angle = (j + dx * a[i] + 720) % 360;
                can_make[angle] = true;
            }
        }
    }

    int x;
    while (k-- > 0) {
        scanf("%d", &x);
        printf("%s\n", can_make[x] ? "YES" : "NO");
    }

    return 0;
}
