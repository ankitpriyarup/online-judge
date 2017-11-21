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

constexpr int MAXN = 1003;
int a[MAXN];

void stack_out(vector<int>& stk) {
    int last = stk.back();
    stk.pop_back();
    int first = last;
    while (!stk.empty() and stk.back() + 1 == first) {
        first = stk.back();
        stk.pop_back();
    }

    if (first + 1 < last) {
        printf("%d-%d ", first, last);
    } else {
        for (int k = first; k <= last; ++k)
            printf("%d ", k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
        if (!stk.empty() and stk.back() + 1 != a[i]) {
            stack_out(stk);
        }

        stk.push_back(a[i]);
    }

    if (!stk.empty())
        stack_out(stk);

    printf("\n");

    return 0;
}
