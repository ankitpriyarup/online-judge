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
char s[MAXN];
int n;
int freq[MAXN][26];
int target[26];

bool works(int x) {
    for (int i = 0; i < 26; ++i) {
        target[i] = freq[x - 1][i];
    }

    for (int y = 2 * x - 1; y < n; y += x) {
        for (int j = 0; j < 26; ++j) {
            if (freq[y][j] - freq[y - x][j] != target[j]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (i)
            for (int j = 0; j < 26; ++j) {
                freq[i][j] += freq[i - 1][j];
            }

        ++freq[i][s[i] - 'a'];
    }

    int best = n;
    for (int x = 1; x * x <= n; ++x) {
        if (n % x) continue;

        if (works(x)) {
            best = x;
            break;
        } else if (works(n / x)) {
            best = min(best, n / x);
        }
    }

    if (best == n) {
        printf("%d\n", -1);
    } else {
        s[best] = '\0';
        printf("%s\n", s);
    }

    return 0;
}
