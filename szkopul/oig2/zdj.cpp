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

constexpr int MAXN = 200005;
int sz;
int tree[6 * MAXN];
int lazy[6 * MAXN];

void push(int node, int l, int r) {
    tree[node] += lazy[node];

    if (l != r) {
        lazy[2 * node]     += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void pull(int node) {
    tree[node] = max(tree[2 * node]     + lazy[2 * node], 
                     tree[2 * node + 1] + lazy[2 * node + 1]);
}

void update(int node, int l, int r, int ql, int qr, int v) {
    if (l == ql and r == qr) {
        lazy[node] += v;
        return;
    }

    push(node, l, r);

    int mid = (l + r) >> 1;
    if (ql <= mid) {
        update(2 * node, l, mid, ql, min(mid, qr), v);
    }
    if (mid < qr) {
        update(2 * node + 1, mid + 1, r, max(ql, mid + 1), qr, v);
    }

    pull(node);
}

void update(int l, int r, int v) {
    update(1, 0, sz - 1, l, r, v);
}

struct event {
    int x, d, y1, y2;

    bool operator<(const event& other) const {
        if (x == other.x) {
            if (d == other.d) {
                if (y1 == other.y1) {
                    return y2 < other.y2;
                }

                return y1 < other.y1;
            }

            return d < other.d;
        }

        return x < other.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    vector<event> events;

    int x1, y1, x2, y2;
    vector<int> all_y;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        events.push_back({x1, 1, y1, y2});
        events.push_back({x2, -1, y1, y2});
        all_y.push_back(y1);
        all_y.push_back(y2);
    }

    sort(begin(events), end(events));
    sort(begin(all_y), end(all_y));
    all_y.erase(unique(begin(all_y), end(all_y)), end(all_y));

    sz = all_y.size();

    /*
    for (int y : all_y) {
        printf("%d ", y);
    }
    printf("\n");
    */

    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));

    int ans = 1;
    for (const auto& evt : events) {
        int l = lower_bound(begin(all_y), end(all_y), evt.y1) - begin(all_y);
        int r = lower_bound(begin(all_y), end(all_y), evt.y2) - begin(all_y);
        int d = evt.d;

        // printf("Updating range from %d to %d (orig %d, %d) with val %d\n", l, r, evt.second.first, evt.second.second, d);

        update(l, r - 1, d);
        ans = max(ans, tree[1] + lazy[1]);
        // printf("%d %d\n", tree[1], lazy[1]);
    }

    printf("%d\n", ans);

    return 0;
}
