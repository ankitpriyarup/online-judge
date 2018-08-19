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

    int k, n;
    scanf(" %d", &k);
    scanf(" %d", &n);

    vector<int> freq(10, 0);
    int x;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &x);
        ++freq[x / 1000];
    }

    int pages = 2;
    for (int i = 0; i < 10; ++i) {
        pages += (freq[i] + k - 1) / k;
    }
    printf("%d\n", pages);

    return 0;
}
