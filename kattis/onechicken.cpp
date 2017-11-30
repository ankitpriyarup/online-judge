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
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);
    if (n < m) {
        printf("Dr. Chaz will have %d %s of chicken left over!\n", m - n, m - n == 1 ? "piece" : "pieces");
    } else {
        printf("Dr. Chaz needs %d more %s of chicken!", n - m, n - m == 1 ? "piece" : "pieces");
    }
    
    return 0;
}
