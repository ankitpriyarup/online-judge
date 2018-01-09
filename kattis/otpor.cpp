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

int n;
ld a[10];
char s[100005];
int p = 0;

ld parse() {
    if (s[p] == '(') {
        // printf("Begin group\n");
        ++p;
        vector<ld> vals;
        vals.push_back(parse());
        // printf("First value in group is %.2Lf\n", vals.back());
        char kind = s[p];
        // printf("Group is of kind %c\n", kind);
        while (s[p] != ')') {
            ++p;
            vals.push_back(parse());
            // printf("Added val %.2Lf\n", vals.back());
        }

        ++p;

        if (kind == '-') {
            ld res = 0;
            for (ld x : vals)
                res += x;

            return res;
        } else {
            ld res = 0;
            for (ld x : vals)
                res += (1.0 / x);

            return 1.0 / res;
        }
    } else if (s[p] == 'R') {
        p += 2;
        return a[s[p - 1] - '0'];
    }

    assert(0);
    return -1.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%Lf", a + i);
    scanf("%s", s);

    p = 0;
    ld res = parse();

    printf("%.17Lf\n", res);

    return 0;
}
