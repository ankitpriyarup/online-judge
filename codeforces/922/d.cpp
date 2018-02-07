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

struct chunk {
    string val;
    int s, h;

    chunk(): s(0), h(0), val("") {}
    chunk(string& str): s(0), h(0), val(str) {
        for (char c : str) {
            if (c == 's')
                ++s;
            else if (c == 'h')
                ++h;
        }
    }

    bool operator<(const chunk& other) const {
        ll me_first = 1LL * s * other.h;
        ll me_second = 1LL * other.s * h;

        return me_first > me_second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<chunk> chunks(n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        chunks[i] = chunk(s);
    }

    sort(begin(chunks), end(chunks));
    int s_count = 0;
    ll ans = 0LL;
    for (const chunk& part : chunks) {
        for (int j = 0; j < part.val.size(); ++j) {
            char c = part.val[j];
            if (c == 's')
                ++s_count;
            else
                ans += s_count;
        }
    }

    cout << ans << '\n';

    return 0;
}
