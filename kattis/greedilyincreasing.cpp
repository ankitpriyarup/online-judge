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
    int x;
    scanf("%d", &x);
    vector<int> gis;
    gis.push_back(x);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        if (x > gis.back()) {
            gis.push_back(x);
        }
    }

    printf("%lu\n", gis.size());
    for (int x : gis) {
        printf("%d ", x);
    }
    
    return 0;
}
