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
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q-- > 0) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        vector<int> odds;
        for (int i = 0; i < n; ++i) {
            int& x = a[i];
            cin >> x;
            x %= 2;

            if (x)
                odds.push_back(i);
        }

        if (odds.size() < k or odds.size() % 2 != k % 2) {
            cout << "NO\n";
            continue;
        } else {
            cout << "YES\n";
            for (int i = 0; i < k - 1; ++i) {
                cout << (odds[i] + 1) << ' ';
            }
            cout << n << '\n';
        }
    }

    return 0;
}
