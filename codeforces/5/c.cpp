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

constexpr int MAXN = 1000006;
int n;
char s[MAXN];
int good_len[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    int best = 0;
    int ways = 1;
    vector<int> stk;
    pii cur = {0, 0};
    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stk.push_back(i);
            ++p;
        } else {
            if (p) {
                int len = i - stk.back() + 1;
                stk.pop_back();

                good_len[p] = 0;
                --p;
                len += good_len[p];
                good_len[p] = len;

                if (len > best) {
                    best = len;
                    ways = 0;
                }
                if (len == best) {
                    ways++;
                }
            }
            else
                good_len[0] = 0;
        }
    }

    printf("%d %d\n", best, ways);
    return 0;
}
