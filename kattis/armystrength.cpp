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

    int T;
    scanf(" %d", &T);
    int n, m;
    while (T-- > 0) {
        scanf("%d %d", &n, &m);
        vector<int> a(n);
        vector<int> b(m);

        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < m; ++i) {
            scanf("%d", &b[i]);
        }
        sort(begin(a), end(a));
        reverse(begin(a), end(a));

        sort(begin(b), end(b));
        reverse(begin(b), end(b));

        while (!a.empty() and !b.empty()) {
            if (a.back() < b.back()) {
                a.pop_back();
            } else {
                b.pop_back();
            }
        }

        if (a.empty()) {
            printf("MechaGodzilla\n");
        } else {
            printf("Godzilla\n");
        }
    }
    
    return 0;
}
