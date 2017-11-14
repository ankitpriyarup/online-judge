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

constexpr int MAXN = 10000007;
char a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s %s", a, b);
    int n = strlen(a);
    int last_shift = 0;
    int score = 0;

    for (int i = 0; i < n; ++i) {
        int needed = b[i] - a[i];

        if (needed > 0) {
            score += min(needed, max(0, last_shift >= 0 ? needed - last_shift : 33));
        } else if (needed < 0) {
            score += min(-needed, max(0, last_shift <= 0 ? last_shift - needed : 33));
        }

        last_shift = needed;
    }

    printf("%d\n", score);
    
    return 0;
}
