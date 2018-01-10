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

constexpr int MAXN = 100005;
int n;
string type[MAXN], word[MAXN];

bitset<30> to_bs(const string& s) {
    bitset<30> res;
    for (char c : s) {
        res[c - 'a'] = true;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    bitset<30> all = to_bs("abcdefghijklmnopqrstuvwxyz");
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        cin >> type[i] >> word[i];
        bitset<30> cur = to_bs(word[i]);

        if (type[i][0] == '!') {
            if (all.count() <= 1) {
                ans += 1;
            }
            all = all & cur;
        } else if (type[i][0] == '.') {
            all = all & cur.flip();
        } else {
            if (all.count() == 1)
                ans += 1;
            all.reset(word[i][0] - 'a');
        }
    }

    cout << max(0, ans - 1) << '\n';

    return 0;
}
