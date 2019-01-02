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

void rebalance(multiset<int>& small, multiset<int>& large) {
    while (small.size() + 1 < large.size()) {
        int x = *begin(large);
        small.insert(x);
        large.erase(begin(large));
    }
    while (large.size() < small.size()) {
        auto it = prev(end(small));
        large.insert(*it);
        small.erase(it);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    multiset<int> small, large;
    while (cin >> s) {
        if (s == "#") {
            cout << *begin(large) << '\n';
            large.erase(begin(large));
        } else {
            int x = stoi(s);
            if (large.empty() or x >= *begin(large)) {
                large.insert(x);
            } else {
                small.insert(x);
            }
        }

        rebalance(small, large);
    }
    
    return 0;
}
