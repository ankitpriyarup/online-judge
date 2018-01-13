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
    vector<int> stk;
    vector<vector<int> > vals;
    vals.push_back(vector<int>());
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stk.push_back(i);
            vals.push_back(vector<int>());
        } else {
            int start = stk.back();
            stk.pop_back();

            int len = i - start + 1;
            if (vals.back().size() >= 2) {
                ll cur = 0LL;
                for (int j = 0; j < vals.back().size(); ++j) {
                    for (int k = j + 1; k < vals.back().size(); ++k) {
                        cur += vals.back()[j] * vals.back()[k];
                    }
                }

                ans += cur * len;
            }

            vals.pop_back();
            vals.back().push_back(len >> 1);
        }
    }

    printf("%lld\n", ans);

    return 0;
}
