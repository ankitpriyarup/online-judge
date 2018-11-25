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

int costs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int prefixes[] = {888, 108, 188, 200, 208, 288, 688};
int real_min[102];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i < 100000; ++i) {
        int x = i;
        int sticks = 0;
        while (x) {
            sticks += costs[x % 10];
            x /= 10;
        }

        if (!real_min[sticks])
            real_min[sticks] = i;
    }
    
    int T;
    cin >> T;

    int n;
    while (T-- > 0) {
        cin >> n;
        // max first
        int len = n / 2;
        string max_ans = n % 2 == 1 ? "7" : "1";
        for (int i = 1; i < len; ++i) {
            max_ans.push_back('1');
        }

        // min ans
        string min_ans = "";
        if (real_min[n] != 0) {
            min_ans = to_string(real_min[n]);
        } else {
            min_ans = to_string(prefixes[n % 7]);
            int used = 0;
            for (char c : min_ans) {
                used += costs[c - '0'];
            }

            while (used < n) {
                min_ans.push_back('8');
                used += 7;
            }
        }
        cout << min_ans << ' ' << max_ans << '\n';
    }
    return 0;
}
