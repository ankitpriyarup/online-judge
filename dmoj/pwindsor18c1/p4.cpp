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

    vector<int> freq(300, 0);

    string s;
    for (int k = -1; k <= 1; k += 2) {
        cin >> s;
        for (size_t i = 0; i < s.size(); ++i) {
            freq[s[i]] += k;
        }
    }

    for (int i = 0; i < 300; ++i) {
        if (freq[i] != 0) {
            char res = i;
            cout << res << '\n';
            return 0;
        }
    }

    return 0;
}
