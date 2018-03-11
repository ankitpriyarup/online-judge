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
int n;
char s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);
    char goal = 'a';
    for (int i = 0; i < n; ++i) {
        if (goal > 'z')
            break;

        if (s[i] <= goal) {
            s[i] = goal;
            ++goal;
        }
    }

    if (goal > 'z') {
        printf("%s\n", s);
    } else {
        printf("%d\n", -1);
    }

    return 0;
}
