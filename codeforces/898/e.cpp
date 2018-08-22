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

    vector<int> squares;
    for (int i = 0; i < 32000; ++i) {
        squares.push_back(i * i);
    }

    int n;
    cin >> n;
    vector<int> a, b;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        auto it = lower_bound(begin(squares), end(squares), x);
        if (it != end(squares) and *it == x) {
            a.push_back(x);
        } else {
            b.push_back(x);
        }
    }

    if (a.size() > b.size()) {
        sort(begin(a), end(a));

        // can change sq to non sq by adding 1
        int moves = (a.size() - b.size()) >> 1;
        int ans = moves;
        while (moves-- > 0) {
            // add extra for 0
            ans += a.back() == 0;
            a.pop_back();
        }
        
        printf("%d\n", ans);
    } else {
        // for each number, find its cost to make square
        // pick the cheapest
        vector<int> costs;
        for (int x : b) {
            auto it = upper_bound(begin(squares), end(squares), x);
            // printf("For %d, next is %d prev is %d\n", x, *it, *prev(it));
            int after = *it - x;
            int bef = x - (*prev(it));
            costs.push_back(min(after, bef));
            // printf("Cost %d\n", costs.back());
        }

        sort(begin(costs), end(costs));
        reverse(begin(costs), end(costs));
        int moves = (b.size() - a.size()) >> 1;
        ll ans = 0;
        while (moves --> 0) {
            ans += costs.back();
            costs.pop_back();
        }

        printf("%lld\n", ans);
    }

    return 0;
}
