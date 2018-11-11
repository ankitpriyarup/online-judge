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

using ld = long double;
using pii = pair<int, int>;

bool harshad(int n) {
    int digsum = 0;
    int x = n;
    while (n > 0) {
        digsum += (n % 10);
        n /= 10;
    }

    return x % digsum == 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    while (!harshad(n))
        ++n;

    cout << n;

    
    return 0;
}
