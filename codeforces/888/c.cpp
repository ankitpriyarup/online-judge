#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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

constexpr int MAXN = 100005;
int n;
char s[MAXN];

bool works(char c, int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == c)
            ++sum;
    }

    if (!sum) return false;

    for (int i = len; i < n; ++i) {
        if (s[i - len] == c)
            --sum;
        if (s[i] == c)
            ++sum;

        if (!sum) return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    int lo = 0;
    int hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        bool flag = false;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (works(c, mid)) {
                flag = true;
                break;
            }
        }

        if (flag) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%d\n", hi);

    return 0;
}
