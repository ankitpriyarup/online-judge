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

constexpr int MAXM = 400005;
int freq[MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (ll i = 1; i * i * i < MAXM; ++i) {
        ll i3 = i * i * i;
        for (ll j = i; i3 + j * j * j < MAXM; ++j) {
            ll j3 = j * j * j;
            ++freq[i3 + j3];
        }
    }

    int x;
    scanf("%d", &x);
    int ans = -1;
    for (int i = 0; i <= x; ++i) {
        if (freq[i] >= 2) {
            ans = i;
        }
    }

    if (ans == -1) {
        printf("%s\n", "none");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
