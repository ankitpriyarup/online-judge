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
    vector<int> v(n, 0);
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
        --v[i];
    }

    vector<int> stk = {n - 1};
    while (stk.back() != 0)
        stk.push_back(v[stk.back()]);

    while (!stk.empty()) {
        cout << (stk.back() + 1) << ' ';
        stk.pop_back();
    }


    return 0;
}
