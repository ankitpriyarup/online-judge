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

int n;
char s[300];
char t[2][300];
int p[2];

void shuffle() {
    int k = 0;
    p[0] = p[1] = 0;
    for (int i = n - 1; i >= 0; --i) {
        t[k][p[k]++] = s[i];
        k = 1 - k;
    }

    for (int i = 0; i < p[1]; ++i) {
        s[i] = t[1][i];
    }
    for (int i = 0; i < p[0]; ++i) {
        s[i + p[1]] = t[0][i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int k;
    scanf("%s", s);
    scanf("%d", &k);
    n = strlen(s);

    for (int kk = 0; kk < k; ++kk) {
        shuffle();
    }

    printf("%s\n", s);
    
    return 0;
}
