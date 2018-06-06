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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    vector<int> v(n + 1, 1);
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2 * i; j <= n; j += i) {
            while (v[i] == v[j])
                ++v[j];
            ans = max(ans, v[j]);
        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i)
        printf("%d ", v[i]);
    
    return 0;
}
