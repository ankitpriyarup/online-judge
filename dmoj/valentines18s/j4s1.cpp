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

int convert(int len, int right) {
    int res = 0;
    for (int i = 0; i < len; ++i) {
        res *= 10;
        res += right % 10;
        right /= 10;
    }

    return res;
}

void update(int n, int i, int m, int& best_score, int& ans) {
    int score = min(i - n, m - i); 
    if (score >= best_score) { 
        ans = i;
        best_score = score;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);
    int best_score = -1;
    int ans = -1;
    for (int i = 1; i < 10; ++i) {
        if (n <= i and i <= m) {
            update(n, i, m, best_score, ans);
        }
    }

    for (int len = 2; len <= 8; ++len) {
        int exp = len / 2;
        int base = 1;
        for (int x = 0; x < exp; ++x)
            base *= 10;

        for (int right = 1; right < base; ++right) {
            if (right % 10 == 0) continue;

            int left = convert(len / 2, right);
            if (len % 2 == 1) {
                for (int center = 0; center < 10; ++center) {
                    int val = left * base * 10 + center * base + right;
                    update(n, val, m, best_score, ans);
                    // printf("%d\n", val);
                }
            } else {
                int val = left * base + right;
                update(n, val, m, best_score, ans);
                // printf("%d\n", val);
            }
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
