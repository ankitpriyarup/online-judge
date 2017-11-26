#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
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

bool used[30];
int score[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    scanf("%d", &q);
    char buf[3];
    int x;
    while (q-- > 0) {
        scanf("%s %d", buf, &x);
        used[buf[0] - 'A'] = true;
        score[buf[0] - 'A'] += x;
    }

    for (int i = 0; i < 26; ++i) {
        if (used[i]) {
            printf("%c %d\n", 'A' + i, score[i]);
        }
    }

    return 0;
}
