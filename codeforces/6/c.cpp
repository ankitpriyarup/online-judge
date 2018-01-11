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

constexpr int MAXN = 100005;
int n;
int a[MAXN];
int p[MAXN];
int delta[] = {1, -1};
bool eaten[MAXN];
int score[2];

struct evt {
    ll time, person, pos;
    bool operator<(const evt& other) const {
        return tie(time, person) < tie(other.time, other.person);
    }
    bool operator==(const evt& other) const {
        return tie(time, person) == tie(other.time, other.person);
    }
    bool operator>(const evt& other) const {
        return !(*this < other) and !(*this == other);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    p[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        p[i] = a[i] + p[i - 1];
    }

    priority_queue<evt, vector<evt>, greater<evt> > pq;
    pq.push({0, 0, 1});
    pq.push({0, 1, n});

    memset(eaten, false, 0);
    int time, person, pos;
    while (!pq.empty()) {
        evt e = pq.top();
        pq.pop();

        if (e.pos > n or e.pos <= 0 or eaten[e.pos]) continue;

        eaten[e.pos] = true;
        ++score[e.person];
        pq.push({e.time + a[e.pos], e.person, e.pos + delta[e.person]});
    }

    printf("%d %d\n", score[0], score[1]);
    return 0;
}
