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

constexpr int MAXN = 300;
char s[MAXN];
char t[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    char last = '\0';
    int n = strlen(s);
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != last) {
            t[p++] = s[i];
        }
        last = s[i];
    }
    t[p] = 0;
    printf("%s\n", t);
    return 0;
}
