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
constexpr int MAX_NODES = 1000006;
int n;
int trie[MAX_NODES][30];
int cur;
int next_node = 1;

void insert(const string& s) {
    int node = 0;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (trie[node][c - 'a'] == -1) {
            trie[node][c - 'a'] = next_node++;
            cur = min(cur, i + 1);
        }

        node = trie[node][c - 'a'];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    int tc = 1;
    string s;
    while (T-- > 0) {
        cin >> n;
        memset(trie, -1, sizeof(trie));
        next_node = 1;

        ll ans = 0LL;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            cur = s.size();
            insert(s);
            ans += cur;
        }

        cout << "Case #" << tc++ << ": " << ans << '\n';
    }

    return 0;
}
