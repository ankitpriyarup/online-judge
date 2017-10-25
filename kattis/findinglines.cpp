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
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <random>
#include <tuple>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100005;
constexpr int TRIALS = 60;
int n, p;
int x[MAXN], y[MAXN];
map<int, int> freq_x, freq_y;

ll gcd(const ll& a, const ll& b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool collect(int src) {
    // printf("collect(%d)\n", src);
    map<tuple<ll, ll, ll, ll>, int> freq;
    tuple<ll, ll, ll, ll> best_line{0, 0, 0, 0};

    for (int i = 0; i < n; ++i) {
        if (i == src)
            continue;

        // y - y1 = (y2 - y1)/(x2 - x1) (x - x1)
        // (y - y1)(x2 - x1) = (y2 - y1) (x - x1)
        // y (x2 - x1) - y1 (x2 - x1) = x (y2 - y1) - x1 (y2 - y1)
        // -x(y2 - y1) + y (x2 - x1) = y1 (x2 - x1) - x1 (y2 - y1)
        ll xd = x[src] - x[i];
        ll yd = y[src] - y[i];

        // dont consider horizontal lines
        if (xd == 0 or yd == 0) continue;

        ll g = gcd(xd, yd);

        xd /= g;
        yd /= g;

        // y = mx + b
        // y - x * yd / xd = b

        ll b = y[i] - yd * x[i] / xd;
        ll br = yd * x[i] % xd;

        // printf("Line from (%d %d) to (%d %d) has hash (%lld, %lld, %lld, %lld)\n", x[i], y[i], x[src], y[src], xd, yd, b, br);
        tuple<ll, ll, ll, ll> line{xd, yd, b, br};

        ++freq[line];
        if (freq[line] > freq[best_line]) {
            best_line = line;
        }
    }

    int pts = freq[best_line] + 1;

    return pts >= (n * p + 99) / 100;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &p);
    vector<int> inds;
    int best_x = 0;
    int best_y = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, y + i);
        ++freq_x[x[i]];
        ++freq_y[y[i]];

        if (freq_x[x[i]] > freq_x[best_x])
            best_x = x[i];

        if (freq_y[y[i]] > freq_y[best_y])
            best_y = y[i];

        inds.push_back(i);
    }

    random_shuffle(begin(inds), end(inds));
    // printf("%d %d %d %d\n", best_x, freq_x[best_x], best_y, freq_y[best_y]);
    bool found = freq_x[best_x] >= (n * p + 99) / 100;
        found |= freq_y[best_y] >= (n * p + 99) / 100;

    for (int t = 0; !found and t < min(n, TRIALS); ++t) {
        int idx = inds[t];

        if (collect(idx)) {
            found = true;
        }
    }

    printf("%s\n", found ? "possible" : "impossible");

    return 0;
}
