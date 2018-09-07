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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    sort(begin(a), end(a));
    sort(begin(b), end(b));
    ll delta = 0LL;
    int move = 0;
    while (!a.empty() or !b.empty()) {
        // cout << "A: " << a.size() << " B: " << b.size() << '\n';
        if (move == 0) {
            // a move
            if (b.empty() or (!a.empty() and a.back() > b.back())) {
                delta += a.back();
                a.pop_back();
            } else {
                b.pop_back();
            }
        } else {
            // b
            if (a.empty() or (!b.empty() and b.back() > a.back())) {
                delta -= b.back();
                b.pop_back();
            } else {
                a.pop_back();
            }
        }

        move ^= 1;
    }

    cout << delta << '\n';

    return 0;
}
