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

    char buf[30];
    int T;
    scanf(" %d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        int n;
        scanf(" %d", &n);
        vector<int> red, blue;
        for (int i = 0; i < n; ++i) {
            scanf(" %s", buf);
            int m = strlen(buf);
            char color = buf[m - 1];
            buf[m - 1] = '\0';
            int x = atoi(buf);
            if (color == 'R') {
                red.push_back(x);
            } else {
                blue.push_back(x);
            }
        }

        sort(begin(red), end(red));
        sort(begin(blue), end(blue));
        int ans = 0;
        while (!red.empty() and !blue.empty()) {
            ans += red.back();
            ans += blue.back();
            ans -= 2;
            red.pop_back();
            blue.pop_back();
        }

        printf("Case #%d: %d\n", tc, ans);
    }
    
    return 0;
}
