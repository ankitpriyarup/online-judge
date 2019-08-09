#include <tuple>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define all(x) begin(x), end(x)

struct BIT {
    int n;
    vector<int> data;
    BIT(int n): n(n) {
        data.assign(n + 1, 0);
    }

    int query(int x) const {
        x += 1;
        int res = 0;
        for (; x > 0; x -= (x & -x)) {
            res += data[x];
        }
        return res;
    }

    int query(int x, int y) const {
        if (x > y) return 0;
        return query(y) - query(x - 1);
    }

    void update(int x, int v) {
        x += 1;
        for (; x < data.size(); x += (x & -x)) {
            data[x] += v;
        }
    }
};

// x, kind, y1, y2
using event = tuple<int, int, int, int>;

// sweepline solution
// assumes that all x and y coordinates are distinct.
int main() {
    int n;
    scanf(" %d", &n);
    vector<event> events;
    vector<int> all_x, all_y;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        scanf(" %d %d %d %d", &x1, &y1, &x2, &y2);
        // vertical lines are queries
        events.emplace_back(x1, 0, y1, y2);
        events.emplace_back(x2, 0, y1, y2);

        // horizontal lines are add and remove at a y
        events.emplace_back(x1, 1, y1, y1);
        events.emplace_back(x1, 1, y2, y2);
        events.emplace_back(x2, -1, y1, y1);
        events.emplace_back(x2, -1, y2, y2);

        all_x.push_back(x1);
        all_x.push_back(x2);
        all_y.push_back(y1);
        all_y.push_back(y2);
    }

    // sort + uniq
    // uniq shouldn't do anything
    sort(all(all_x));
    sort(all(all_y));
    all_x.erase(unique(all(all_x)), end(all_x));
    all_y.erase(unique(all(all_y)), end(all_y));
    assert(all_x.size() == (n << 1));
    assert(all_y.size() == (n << 1));

    sort(all(events));
    BIT bit(all_y.size());
    bool poss = false;
    for (auto& e : events) {
        int x, op, y1, y2;
        tie(x, op, y1, y2) = e;
        int j1 = lower_bound(all(all_y), y1) - begin(all_y);
        if (op == 0) {
            // query
            int j2 = lower_bound(all(all_y), y2) - begin(all_y);
            if (bit.query(j1 + 1, j2 - 1)) {
                poss = true;
                break;
            }
        } else {
            bit.update(j1, op);
        }
    }

    printf("%d\n", poss);

    return 0;
}
