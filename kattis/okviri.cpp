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

char s[20];
char out[5][400];
int n;

int dx[] = {-2, -1, -1, 0, 0, 1, 1, 2};
int dy[] = {0, -1, 1, -2, 2, -1, 1, 0};

void surround(int x, int y, char c) {
    for (int d = 0; d < 8; ++d) {
        out[x + dx[d]][y + dy[d]] = c;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 1 + 4 * n; ++j)
            out[i][j] = '.';
    }

    for (int i = 0; i < n; ++i) {
        out[2][2 + 4 * i] = s[i];
        surround(2, 2 + 4 * i, '#');
    }

    for (int i = 2; i < n; i += 3) {
        surround(2, 2 + 4 * i, '*');
    }

    for (int i = 0; i < 5; ++i) {
        printf("%s\n", out[i]);
    }

    return 0;
}
