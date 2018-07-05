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
int n, m;
int a[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &m);
    multiset<pii> greater;
    int t, p;
    while (m-- > 0) {
        scanf(" %d %d", &t, &p);
        pii old_val = {a[t], b[t]};
        ++a[t];
        b[t] -= p;
        pii me = {a[1], b[1]};

        if (t == 1) {
            while (!greater.empty() and *begin(greater) <= me) {
                greater.erase(begin(greater));
            }
        } else {
            if (old_val > me) {
                auto it = greater.find(old_val);
                greater.erase(it);
            }
            pii new_val = {a[t], b[t]};
            if (new_val > me) {
                greater.insert(new_val);
            }
        }
        printf("%lu\n", greater.size() + 1);
    }

    return 0;
}
