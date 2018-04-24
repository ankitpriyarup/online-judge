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

char a[10], b[10];
int freq[15];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %s", a);
    scanf(" %s", b);

    int bulls = 0;
    int cows = 0;
    for (int i = 0; i < 4; ++i) {
        if (a[i] == b[i]) ++bulls;
        ++freq[a[i] - '0'];
        ++freq[b[i] - '0'];
    }

    for (int i = 0; i < 10; ++i) {
        if (freq[i] >= 2) {
            ++cows;
        }
    }

    printf("%d %d\n", bulls, cows - bulls);
    
    return 0;
}
