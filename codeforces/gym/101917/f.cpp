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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    string s;
    while (T-- > 0) {
        cin >> s;
        int idx = s.find('.');
        if (s[0] == '1' or idx == string::npos) {
            cout << "1\n";
            continue;
        }

        s = s.substr(idx + 1);
        while (s.size() < 4) {
            s.push_back('0');
        }

        if (s == "0000") {
            cout << "1\n";
            continue;
        }

        int d = stoi(s);
        cout << (10000 / gcd(10000, d)) << '\n';
    }

    return 0;
}
