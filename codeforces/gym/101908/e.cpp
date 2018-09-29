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

vector<vector<int>> agg(const string& s) {
    vector<vector<int>> res(26);
    for (size_t i = 0; i < s.size(); ++i) {
        res[s[i] - 'A'].push_back(i);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string hay, needle;
    cin >> hay >> needle;
    int n = hay.size();
    int m = needle.size();
    vector<vector<int>> hay_pos = agg(hay);
    vector<vector<int>> need_pos = agg(needle);
    vector<char> pos(n, 1);
    int ans = n;
    for (int i = n - m + 1; i < n; ++i) {
        pos[i] = 0;
        --ans;
    }

    for (int x = 0; x < 26; ++x) {
        for (int i : hay_pos[x]) {
            for (int j : need_pos[x]) {
                if (i - j >= 0 and pos[i - j]) {
                    pos[i - j] = 0;
                    --ans;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
