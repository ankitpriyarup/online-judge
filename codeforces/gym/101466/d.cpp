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
    scanf(" %d", &n);
    string s;
    while (n) {
        if (n & 1) {
            s.push_back('A');
            n -= 1;
        } else {
            s.push_back('B');
            n -= 2;
        }
        n >>= 1;
    }

    reverse(begin(s), end(s));
    printf("%s\n", s.c_str());
    
    return 0;
}
