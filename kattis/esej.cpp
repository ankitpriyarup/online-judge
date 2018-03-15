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

    int a, b;
    cin >> a >> b;
    int sz = max(a, (b + 1) >> 1);
    for (int i = 1; i <= sz; ++i) {
        string s;
        for (int j = 0; j < 15; ++j) {
            int v = rand() % 26;
            s.push_back(v + 'a');
        }

        cout << s;
        if (i < sz)
            cout << ' ';
    }
    cout << '\n';
    
    return 0;
}
