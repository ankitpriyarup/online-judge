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

constexpr int n = 10;
ll usage[n], recovery[n];

ll block_usage[n], block_recovery[n], block_start[n];
ll block_time[n];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < n; ++i)
        scanf("%lld %lld", usage + i, recovery + i);

    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", block_usage + i, block_recovery + i, block_start + i);
        block_time[i] = block_start[i];
    }

    ll time = 0;
    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < n; ++i) {
            if (time < block_start[i]) {
                block_start[i] = max(block_start[i], time + usage[i]);
            } else {
                ll relative = (time - block_start[i]) % (block_usage[i] + block_recovery[i]);
                ll recv;
                if (relative < block_usage[i]) {
                    time += block_usage[i] - relative;
                    recv = block_recovery[i];
                } else {
                    recv = block_usage[i] + block_recovery[i] - relative;
                }

                block_start[i] = max(time + usage[i], time + recv);
            }

            time += usage[i] + recovery[i];
        }
    }

    printf("%lld\n", time - recovery[n - 1]);

    return 0;
}
