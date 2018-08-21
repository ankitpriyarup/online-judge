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
    scanf(" %d", &n);
    int block_size = sqrt(n);
    vector<int> v(n);
    iota(begin(v), end(v), 1);
    for (int i = 0; i < n; i += block_size) {
        int end = min(i + block_size, n); 
        reverse(begin(v) + i, begin(v) + end);
    }

    for (int i = 0; i < n; ++i) {
        printf(" %d", v[i]);
    }

    return 0;
}
