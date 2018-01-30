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

constexpr int MAXN = 5003;
char s[MAXN];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int pref = s[i] == ')' ? -1 : 1;
        int qs = 0;
        if (pref < 0) continue;

        for (int j = i + 1; j < n; ++j) {
            if (s[j] == '(') {
                ++pref;
            } else if (s[j] == ')') {
                --pref;
            } else if (s[j] == '?') {
                if (pref > 0) {
                    --pref;
                    ++qs;
                } else {
                    ++pref;
                }
            } else {
                assert(0);
            }

            while (pref < 0 and qs > 0) {
                --qs;
                pref += 2;
            }

            if (pref == 0) {
                ++ans;
            } else if (pref < 0)
                break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
