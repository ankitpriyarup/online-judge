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

char time_str[40];
char ans[40];
char digits[40];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    scanf("%s", time_str);
    scanf("%s", digits);

    int n = strlen(digits);
    for (int i = 0; i < n; ++i) {
        digits[i] -= '0';
    }

    ll time = 0;
    time += 60 * 60 * 10 * (time_str[0] - '0');
    time += 60 * 60 * (time_str[1] - '0');
    time += 60 * 10 * (time_str[3] - '0');
    time += 60 * (time_str[4] - '0');
    time += 10 * (time_str[6] - '0');
    time += (time_str[7] - '0');

    ll diff = 1e18;
    for (int i1 = 0; i1 < n; ++i1) {
        int i = digits[i1];
        for (int i2 = 0; i2 < n; ++i2) {
            int j = digits[i2];
            for (int i3 = 0; i3 < n; ++i3) {
                int k = digits[i3];
                for (int i4 = 0; i4 < n; ++i4) {
                    int l = digits[i4];
                    for (int i5 = 0; i5 < n; ++i5) {
                        int a = digits[i5];
                        for (int i6 = 0; i6 < n; ++i6) {
                            int b = digits[i6];
                            ll cur_time = 0;
                            cur_time += 60 * 60 * 10 * i;
                            cur_time += 60 * 60 * j;
                            cur_time += 60 * 10 * k;
                            cur_time += 60 * l;
                            cur_time += 10 * a;
                            cur_time += b;
                            if (abs(time - cur_time) < diff) {
                                diff = abs(time - cur_time);
                                ans[0] = (i + '0');
                                ans[1] = (j + '0');
                                ans[2] = ':';
                                ans[3] = (k + '0');
                                ans[4] = (l + '0');
                                ans[5] = ':';
                                ans[6] = (a + '0');
                                ans[7] = (b + '0');
                                ans[8] = '\0';
                            }
                        }
                    }
                }
            }
        }
    }

    printf("%s\n", ans);
    
    return 0;
}
