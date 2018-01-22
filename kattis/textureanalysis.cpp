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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char s[10004];
    int n;
    int tc = 1;

    while (true) {
        scanf("%s", s);
        if (!strcmp(s, "END")) break;

        n = strlen(s);

        int white = 0;
        int i = 1;
        while (s[i] == '.') {
            ++i;
            ++white;
        }
        ++i;
        bool valid = true;
        for (; i < n; ) {
            for (int j = 0; j < white; ++j) {
                if (s[i] != '.') {
                    valid = false;
                }
                ++i;
            }

            if (s[i] != '*') {
                valid = false;
            }
            ++i;
        }

        printf("%d %s\n", tc++, valid ? "EVEN" : "NOT EVEN");
    }
    
    return 0;
}
