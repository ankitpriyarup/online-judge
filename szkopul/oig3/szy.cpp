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
using pii = pair<ll, ll>;

constexpr int MAXN = 1e6 + 6;
int n;
char s[MAXN];
char t[MAXN];
int freq[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char target;
    scanf("%d %c\n", &n, &target);
    scanf("%s", s);
    int best = 0;
    for (int i = 0; i < n; ++i)
        if (++freq[s[i] - 'A'] > freq[best])
            best = s[i] - 'A';

    int shift = (best - (target - 'A') + 26) % 26;
    int diff = 0 - 'A' - shift + 26;
    for (int i = 0; i < n; ++i)
        t[i] = 'A' + (s[i] + diff) % 26;
    t[n] = '\0';
    printf("%s\n", t);

    return 0;
}
