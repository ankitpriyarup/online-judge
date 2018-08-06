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
    vector<int> a, b;
    int x;
    for (int i = 0; i < 2 * n; ++i) {
        scanf(" %d", &x);
        a.push_back(x);
    }

    reverse(begin(a), end(a));

    while (!a.empty()) {
        if (!b.empty() and a.back() == b.back()) {
            b.pop_back();
        } else {
            b.push_back(a.back());
        }

        a.pop_back();
    }

    if (b.empty()) {
        printf("%d\n", 2 * n);
    } else {
        printf("impossible\n");
    }
    
    return 0;
}
