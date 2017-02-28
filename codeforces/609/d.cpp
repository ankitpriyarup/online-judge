#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<long long, int> pii;

const int MAXN = 200005;
const int MAXM = 200005;
int n, m, k;
long long s;

// cost of 1 $ in burles
int a[MAXN];
int a_ind[MAXN];

// cost of 1 lb in burles
int b[MAXN];
int b_ind[MAXN];

int type[MAXM];
// cost in $ or lb
long long cost[MAXM];

vector<int> used;

bool works(int days) {
    used.clear();
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for (int i = 1; i <= m; ++i) {
        long long cur_cost = 1LL * (type[i] == 1 ? a[days] : b[days]) * cost[i];
        pq.push(make_pair(cur_cost, i));
    }

    long long ans = 0LL;
    for (int i = 0; i < k; ++i) {
        ans += pq.top().first;
        used.push_back(pq.top().second);

        pq.pop();
    }

    return ans <= s;
}

void print_ans(int days) {
    works(days);
    printf("%d\n", days);
    for (int i = 0; i < k; ++i) {
        int t = type[used[i]];
        int day_bought = t == 1 ? a_ind[days] : b_ind[days];

        printf("%d %d\n", used[i], day_bought);
    }
}

int main() {
    scanf("%d %d %d %lld", &n, &m, &k, &s);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        a_ind[i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", b + i);
        b_ind[i] = i;
    }

    for (int i = 2; i <= n; ++i) {
        if (a[i - 1] < a[i]) {
            a[i] = a[i - 1];
            a_ind[i] = a_ind[i - 1];
        }

        if (b[i - 1] < b[i]) {
            b[i] = b[i - 1];
            b_ind[i] = b_ind[i - 1];
        }
    }

    for (int i = 1; i <= m; ++i) {
        scanf("%d %lld", type + i, cost + i);
    }

    if (!works(n)) {
        printf("%d\n", -1);
    } else if (works(1)) {
        print_ans(1);
    } else {
        int lo = 1;
        int hi = n;

        while (lo + 1 < hi) {
            int mid = (lo + hi) >> 1;

            if (works(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        print_ans(hi);
    }

    return 0;
}
