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

constexpr int MAXN = 100005;
int n;
int a[MAXN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    set<int> cur;
    set<int> all;
    for (int i = 0; i < n; ++i) {
        set<int> follow;
        for (int x : cur) {
            follow.insert(gcd(x, a[i]));
        }

        follow.insert(a[i]);
        swap(cur, follow);
        all.insert(begin(cur), end(cur));
    }

    printf("%lu\n", all.size());
    
    return 0;
}
