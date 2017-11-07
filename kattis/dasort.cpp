#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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

constexpr int MAXN = 1003;
int k;
int n;
int a[MAXN];
int b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%d %d", &k, &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        sort(b, b + n);

        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (ptr < n and a[i] == b[ptr]) {
                ++ptr;
            }
        }

        printf("%d %d\n", k, n - ptr);
    }

    return 0;
}
