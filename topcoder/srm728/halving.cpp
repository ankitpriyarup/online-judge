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

class Halving {
public:
    map<pii, int> memo;
    int score(int a, int b) {
        if (a == b)
            return 0;
        if (a > b) {
            return 1e8;
        }
        if (memo.find({a, b}) != end(memo))
            return memo[{a, b}];
        if (b & 1)
            return memo[{a, b}] = 1 + min(score(a, b / 2), score(a, 1 + b / 2));
        else
            return memo[{a, b}] = 1 + score(a, b / 2);
    }
    int minSteps(vector<int> a) {
        sort(begin(a), end(a));
        queue<int> q;
        set<int> cands;
        q.push(a[0]);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            bool novel = cands.insert(x).second;
            if (novel and x > 1) {
                q.push(x / 2);
                if (x & 1) {
                    q.push(1 + x / 2);
                }
            }
        }

        int ans = 1e9;
        for (int cand : cands) {
            int cur = 0;
            for (int x : a) {
                cur += score(cand, x);
                if (cur > ans or cur > 1e8)
                    break;
            }
            if (cur < 1e8)
                ans = min(ans, cur);
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
	auto h = Halving();

	cout << h.minSteps(a) << '\n';
    
    return 0;
}
