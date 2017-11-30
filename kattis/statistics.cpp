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

    int n, x;
    int case_num = 1;
    while (scanf("%d", &n) == 1) {
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
        }

        sort(begin(v), end(v));
        printf("Case %d: %d %d %d\n", case_num, v[0], v.back(), v.back() - v[0]);
        ++case_num;
    }
    
    return 0;
}
