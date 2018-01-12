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
int z[MAXN];
bool duped[MAXN];

void z_algorithm() {
    z[0] = n;
    int L = -1, R = -1;

    for (int i = 1; i < n; ++i) {
        z[i] = i >= R ? 0 : min(R-i, z[i-L]);
        while (i+z[i] < n && s[i+z[i]] == s[z[i]]) ++z[i];
        if (i+z[i] > R) L = i, R = i+z[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    z_algorithm();

    int max_rep = 0;
    for (int i = 1; i < n; ++i) {
        max_rep = max(max_rep, z[i]);
    }

    for (int i = max_rep - 1; i >= 0; --i) {
        int start = 0;
        int end = i;
        bool is_pal = true;
        while (is_pal and start < end) {
            is_pal &= s[start] == s[end];
            ++start; --end;
        }

        if (!is_pal) 
            continue;

        printf("%d\n", i + 1);
        return 0;
    }

    printf("%d\n", 0);
    
    return 0;
}
