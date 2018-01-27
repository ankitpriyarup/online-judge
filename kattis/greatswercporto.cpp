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

constexpr int MAXN = 15;
int n;
string word[MAXN];
vector<char> letters;
vector<int> vals;
bool used[10];
int ans = 0;

ll eval(int i) {
    ll res = 0LL;
    for (char c : word[i]) {
        int x = lower_bound(begin(letters), end(letters), c) - begin(letters);
        res *= 10;
        res += vals[x];
    }

    return res;
}

bool works() {
    ll sum = 0LL;
    for (int i = 0; i < n - 1; ++i) {
        sum += eval(i);
    }

    return sum == eval(n - 1);
}

void dfs(int pos) {
    if (pos == letters.size()) {
        ans += works();
        return;
    }

    // 0 has some special handling
    bool can_zero = true;
    for (int i = 0; i < n; ++i) {
        if (word[i][0] == letters[pos]) {
            can_zero = false;
        }
    }

    for (int v = 1 - can_zero; v < 10; ++v) {
        if (used[v]) continue;

        used[v] = true;
        vals[pos] = v;
        dfs(pos + 1);
        used[v] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> word[i];

        for (char c : word[i]) {
            letters.push_back(c);
        }
    }

    sort(begin(letters), end(letters));
    letters.erase(unique(begin(letters), end(letters)), end(letters));

    vals.assign(letters.size(), -1);

    ans = 0;
    dfs(0);

    printf("%d\n", ans);

    return 0;
}
