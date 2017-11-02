#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m;
    string prob, verdict;

    map<string, int> wa;
    set<string> solved;

    int penalty = 0;

    while (cin >> m) {
        if (m == -1) break;
        cin >> prob >> verdict;
        
        if (verdict == "right") {
            if (!solved.count(prob)) {
                penalty += 20 * wa[prob];
                penalty += m;
                solved.insert(prob);
            }
        } else {
            ++wa[prob];
        }
    }

    cout << solved.size() << ' ' << penalty << endl;
    
    return 0;
}
