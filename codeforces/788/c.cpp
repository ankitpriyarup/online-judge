#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1003;
const int MAXL = 10000007;

int n, k;
set<int> pos, neg;
set<int> seen;

int main() {
    ios_base::sync_with_stdio(false);
    scanf("%d %d", &n, &k);

    int x;
    for (int i = 0; i < k; ++i) {
        scanf("%d", &x);
        if (x >= n)
            pos.insert(x - n);
        else
            neg.insert(x - n);
    }

    queue<int> state;
    state.push(0);

    int ans = -1;
    int level = 0;
    while (!state.empty()) {
        int sz = state.size();
        while (sz-- > 0) {
            int cur = state.front();
            state.pop();

            if (cur < -MAXL or cur > MAXL)
                continue;

            if (cur == 0 and level > 0) {
                ans = level;
                state = queue<int>();
                break;
            } else if (level > MAXL) {
                state = queue<int>();
                break;
            }

            if (cur > -1000) {
                for (int nv : neg) {
                    int val = cur + nv;
                    if (seen.find(val) == seen.end()) {
                        seen.insert(val);
                        state.push(val);
                    }
                }
            } 
            if (cur < 1000) {
                for (int nv : pos) {
                    int val = cur + nv;
                    if (seen.find(val) == seen.end()) {
                        seen.insert(val);
                        state.push(val);
                    }
                }
            }
        }

        ++level;
    }

    printf("%d\n", ans);

    return 0;
}
