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

int flip(int x) {
    int a = x % 10;
    int b = (x / 10) % 10;
    int c = (x / 100) % 10;
    return 100 * a + 10 * b + c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    scanf("%d %d", &a, &b);
    a = flip(a);
    b = flip(b);

    printf("%d\n", max(a, b));
    
    return 0;
}
