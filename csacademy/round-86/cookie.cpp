#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, c, s;
    scanf(" %d %d %d", &n, &c, &s);
    vector<pair<ll, ll>> factories(n);
    for (int i = 0; i < n; ++i) {
        scanf(" %lld %lld", &factories[i].first, &factories[i].second);
    }
    ll ans = 1e18;
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> inds;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                inds.push_back(i);
            }
        }
        
        do {
            /*
            printf("Perm: ");
            for (int x : inds) {
                printf("%d ", x);
            }
            printf("\n");
            */

            ll rate = s;
            ll cookies = 0;
            ll t = 0;
            for (int x : inds) {
                // try exiting here based on current rate
                ll to_goal = max(0LL, (c - cookies + rate - 1) / rate);
                ans = min(ans, t + to_goal);

                ll need = factories[x].first;
                ll bump = factories[x].second;
                ll to_fact = max(0LL, (need - cookies + rate - 1) / rate);
                cookies += to_fact * rate;

                assert(cookies >= need);
                cookies -= need;
                rate += bump;
                t += to_fact;
            }

            ll to_goal = max(0LL, (c - cookies + rate - 1) / rate);
            ans = min(ans, t + to_goal);
        } while (next_permutation(begin(inds), end(inds)));
    }
    
    printf("%lld\n", ans);
    return 0;
}
