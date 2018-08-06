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

constexpr int MAXN = 400005;
int n, k;
string s;
bool used[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;
    cin >> s;
    vector<pair<char, int>> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].first = s[i];
        v[i].second = i;
    }

    sort(begin(v), end(v));

    for (int i = 0; i < k; ++i) {
        used[v[i].second] = true;
    }

    string t;
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            t.push_back(s[i]);
    }

    cout << t << '\n';
    
    return 0;
}
