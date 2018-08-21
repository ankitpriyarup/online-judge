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

    string s;
    while (cin >> s) {
        if (s == "0")
            break;

        vector<char> smalls;
        vector<char> bigs;
        int ns = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'N') {
                ++ns;
            } else if (s[i] >= 'p') {
                smalls.push_back(s[i]);
            } else {
                bigs.push_back(s[i]);
            }
        }

        string n_str(ns, 'N');
        int k = min((int)(bigs.size()), (int)(smalls.size()) - 1);
        if (k <= 0) {
            if (smalls.empty())
                cout << "no WFF possible\n";
            else
                cout << n_str << smalls.back() << '\n';

            continue;
        }

        string res;
        for (int i = 0; i < k; ++i) {
            res.push_back(bigs.back());
            bigs.pop_back();
        }

        res += n_str;

        for (int i = 0; i <= k; ++i) {
            res.push_back(smalls.back());
            smalls.pop_back();
        }

        cout << res << '\n';
    }

    return 0;
}
