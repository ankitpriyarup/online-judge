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
constexpr int SQRTN = 320;
int n;
int a[MAXN];
int starts[MAXN];
vector<int> queries[MAXN];

vector<int> freq[SQRTN];
int filled[SQRTN];

template <typename T>
bool contains(const vector<T>& v, T x) {
    auto it = lower_bound(begin(v), end(v), x);
    return it != end(v) and *it == x;
}

void add(int x) {
    for (int i = 0; i < SQRTN; ++i) {
        filled[i] += freq[i][x];
    }
}

bool full(int bucket) {
    int end = min(n, (bucket + 1) * SQRTN);
    return (end - bucket * SQRTN) == filled[bucket];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> all_vals;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        all_vals.push_back(a[i]);
    }

    sort(begin(all_vals), end(all_vals));
    all_vals.erase(unique(begin(all_vals), end(all_vals)), end(all_vals));

    /*
    for (ll x : all_vals)
        cout << x << ' ';
    cout << '\n';
    */

    for (int i = 0; i < SQRTN; ++i)
        freq[i].assign(all_vals.size(), 0);

    for (int i = 0; i < n; ++i) {
        int x = lower_bound(begin(all_vals), end(all_vals), a[i]) - begin(all_vals);
        a[i] = x;
        ++freq[i / SQRTN][x];
    }

    int q, k, x;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> starts[i];
        --starts[i];

        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> x;

            if (!contains<int>(all_vals, x))
                continue;

            int v = lower_bound(begin(all_vals), end(all_vals), x) - begin(all_vals); 
            queries[i].push_back(v);
        }

        sort(begin(queries[i]), end(queries[i]));
    }

    for (int i = 0; i < q; ++i) {
        // cout << "NEW QUERY!\n";

        memset(filled, 0, sizeof(filled));
        for (int x : queries[i]) {
            add(x);
        }

        // p is the maximum index that isn't used
        int p = starts[i];
        while (p < n) {
            if (!contains<int>(queries[i], a[p]))
                break;

            if (p % SQRTN == 0 and full(p / SQRTN)) {
                p += SQRTN;
            } else {
                ++p;
            }
        }

        cout << (min(p, n) - starts[i]) << '\n';
    }

    return 0;
}
