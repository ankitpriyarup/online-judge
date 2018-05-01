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

bool latinspace(char c) {
    if (c == ' ') return true;
    if ('a' <= c and c <= 'z') return true;
    if ('A' <= c and c <= 'Z') return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    getline(cin, s);
    int n = s.size();
    int ans = 0;
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            stk.push_back(i);
        } else if (s[i] == ')') {
            if (!stk.empty()) {
                stk.pop_back();
                ans += stk.size();
                stk.clear();
            } else {
                ++ans;
            }
        } else if (!latinspace(s[i])) {
            ans += stk.size();
            stk.clear();
        }
    }

    ans += stk.size();
    printf("%d\n", ans);

    return 0;
}
