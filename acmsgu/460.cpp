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

int n;
char buf[100];

bool es() {
    return (buf[n - 2] == 'c' and buf[n - 1] == 'h')
        or (buf[n - 1] == 'x')
        or (buf[n - 1] == 's')
        or (buf[n - 1] == 'o');
}

bool f() {
    return (buf[n - 2] == 'f' and buf[n - 1] == 'e')
        or (buf[n - 1] == 'f');
}

bool y() {
    return (buf[n - 1] == 'y');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        scanf("%s", buf);
        n = strlen(buf);
        if (es()) {
            buf[n] = 'e';
            buf[n + 1] = 's';
            buf[n + 2] = '\0';
        } else if (f()) {
            int offset = buf[n - 1] == 'f' ? -1 : -2;
            buf[n + offset] = 'v';
            buf[n + offset + 1] = 'e';
            buf[n + offset + 2] = 's';
            buf[n + offset + 3] = '\0';
        } else if (y()) {
            buf[n - 1] = 'i';
            buf[n + 0] = 'e';
            buf[n + 1] = 's';
            buf[n + 2] = '\0';
        } else {
            buf[n + 0] = 's';
            buf[n + 1] = '\0';
        }

        printf("%s\n", buf);
    }

    return 0;
}
