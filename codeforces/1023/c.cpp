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

constexpr int MAXN = 400005;
int n, k;
char s[MAXN];
char t[MAXN];
bool rem[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d", &n, &k);
    int del = n - k;
    scanf(" %s", s);

    vector<int> stk;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stk.push_back(i);
        } else {
            if (del) {
                del -= 2;
                rem[i] = true;
                rem[stk.back()] = true;
            }

            stk.pop_back();
        }
    }

    int p = 0;
    for (int i = 0; i < n; ++i) {
        if (!rem[i]) {
            t[p++] = s[i];
        }
    }

    printf("%s\n", t);
    
    return 0;
}
