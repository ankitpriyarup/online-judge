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

    int val, ans;
    string junk, resp;
    vector<pii> log;

    while (cin >> val) {
        if (val == 0) break;

        cin >> junk >> resp;
        if (resp == "high") {
            log.emplace_back(0, val);
        } else if (resp == "low") {
            log.emplace_back(1, val);
        } else {
            ans = val;
            bool safe = true;
            for (pii& p : log) {
                if (p.second == ans) {
                    safe = false;
                }
                if (p.first == 0 and p.second < ans) {
                    safe = false;
                }
                if (p.first == 1 and p.second > ans) {
                    safe = false;
                }
            }

            if (safe)
                cout << "Stan may be honest\n";
            else
                cout << "Stan is dishonest\n";

            log.clear();
        }
    }
    
    return 0;
}
