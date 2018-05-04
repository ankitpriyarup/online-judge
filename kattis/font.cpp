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
using bs = bitset<26>;

constexpr int MAXN = 30;
int n;
string words[MAXN];
bs masks[MAXN];
int last[26];
vector<int> last_for[MAXN];
int ans;
bs curmask;

void dfs(int idx) {
    if (curmask.count() == 26) {
        int rem = n - idx;
        ans += (1 << rem);
        return;
    }

    if (idx == n)
        return;

    // try skipping
    bool can_skip = true;
    for (int x : last_for[idx]) {
        if (!curmask[x]) {
            can_skip = false;
            break;
        }
    }

    if (can_skip) {
        dfs(idx + 1);
    }

    // try using
    bs old_mask = curmask;

    curmask |= masks[idx];
    dfs(idx + 1);

    curmask = old_mask;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(last, -1, sizeof(last));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        for (char c : words[i]) {
            masks[i].set(c - 'a'); last[c - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (last[i] == -1)
            return printf("%d\n", 0), 0;
        last_for[last[i]].push_back(i);
    }

    ans = 0;
    dfs(0);

    printf("%d\n", ans);

    return 0;
}
