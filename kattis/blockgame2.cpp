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

bool win(ll a, ll b) {
    if (a > b)
        swap(a, b);

    if (a == 0)
        return false;
    if (b - a >= a)
        return true;

    return !win(a, b - a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll a, b;
    scanf(" %lld %lld", &a, &b);

    printf("%s\n", win(a, b) ? "win" : "lose");

    return 0;
}
