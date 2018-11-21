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

vector<pii> create(int w, const vector<int>& top, const vector<int>& bot) {
    int l = top.size();
    vector<pii> res(l);
    for (int i = 0; i < l; ++i) {
        // height, offset
        res[i] = {w - top[i] - bot[i], bot[i] - bot[0]};
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int w, l, n;
    cin >> w >> l >> n;
    set<vector<pii>> keys;
    
    for (int i = 0; i < n; ++i) {
        vector<int> top(l), bot(l);
        for (int j = 0; j < l; ++j) {
            cin >> top[j];
        }
        for (int j = 0; j < l; ++j) {
            cin >> bot[j];
        }

        vector<pii> key = min(create(w, top, bot), create(w, bot, top));
        reverse(begin(top), end(top));
        reverse(begin(bot), end(bot));
        key = min(key, min(create(w, top, bot), create(w, bot, top)));

        keys.insert(key);
    }

    cout << keys.size() << '\n';
    return 0;
}
