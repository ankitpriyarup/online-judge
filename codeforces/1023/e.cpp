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
int moves = 0;

char buf[100005];

bool move(int r1, int c1, int r2, int c2) {
    if (r1 <= 0 or c1 <= 0 or r2 <= 0 or c2 <= 0) {
        return false;
    }

    if (r1 > n or c1 > n or r2 > n or c2 > n) {
        return false;
    }

    if (moves == 4 * n) {
        return rand() % 2;
    }

    ++moves;
    printf("? %d %d %d %d\n", r1, c1, r2, c2);
    fflush(stdout);
    scanf(" %s", buf);

    assert(r1 <= r2);
    assert(c1 <= c2);

    assert(r2 + c2 - r1 - c1 >= n - 1);

    return buf[0] == 'Y';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d", &n);
    vector<pii> first;
    vector<pii> second;

    first.emplace_back(1, 1);

    // Take path to center diagonal, prefer down over right
    while (first.size() <= n - 1) {
        int rr, cc;
        tie(rr, cc) = first.back();
        if (move(rr + 1, cc, n, n)) {
            first.emplace_back(rr + 1, cc);
        } else {
            first.emplace_back(rr, cc + 1);
        }
    }

    // Take path to center diagonal, prefer left over up
    second.emplace_back(n, n);
    while (second.size() < n - 1) {
        int rr, cc;
        tie(rr, cc) = second.back();

        if (move(1, 1, rr, cc - 1)) {
            second.emplace_back(rr, cc - 1);
        } else {
            second.emplace_back(rr - 1, cc);
        }
    }

    reverse(begin(second), end(second));
    first.insert(end(first), begin(second), end(second));

    for (int i = 1; i < first.size(); ++i) {
        if (first[i - 1].first != first[i].first) {
            buf[i - 1] = 'D';
        } else {
            buf[i - 1] = 'R';
        }

        buf[i] = '\0';
    }

    printf("! %s\n", buf);
    fflush(stdout);
    return 0;
}
