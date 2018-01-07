#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <bitset>
#include <string>

using namespace std;

constexpr int MAXN = 1000006;
int n, m, c;
int a[MAXN];

struct max_queue {
    deque<int> all;
    deque<int> maxq;
    void add(int x) {
        while (!maxq.empty() and maxq.back() < x) {
            maxq.pop_back();
        }

        all.push_back(x);
        maxq.push_back(x);
    }

    void remove() {
        if (all.front() == maxq.front()) {
            maxq.pop_front();
        }

        all.pop_front();
    }

    int get_max() {
        return maxq.front();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d %d %d", &n, &m, &c);

    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    max_queue big;
    max_queue small;
    for (int i = 0; i < m; ++i) {
        big.add(a[i]);
        small.add(-a[i]);
    }

    vector<int> ans;
    if (big.get_max() + small.get_max() <= c) {
        ans.push_back(0);
    }

    for (int i = m; i < n; ++i) {
        big.remove();
        small.remove();

        big.add(a[i]);
        small.add(-a[i]);

        if (big.get_max() + small.get_max() <= c) {
            ans.push_back(i - m + 1);
        }
    }

    for (int x : ans) {
        printf("%d\n", x + 1);
    }

    if (ans.empty()) {
        printf("NONE\n");
    }
    return 0;
}
