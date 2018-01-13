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

    char s[100005];
    scanf("%s", s);
    int n = strlen(s);
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            ++a;
        else
            ++b;
    }

    printf("%d\n", min(a, b));
    
    return 0;
}
