#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algoritm>
#include <utility>
#include <vector>

#define all(x) (x).begin(), (x).end()
 
using namespace std;

const int MAXN = 30004;
const int MAXQ = 200005;
int n;
int a[MAXN];

int f_tree[MAXN];
int ans[MAXQ];

int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= (i & -i)) {
        ans += f_tree[i];
    }

    return ans;
}

void update(int x) {
    for (int i = x; i < MAXN; i += (i & -i)) {
        f_tree[i]++;
    }
}

struct query {
    int l, r, k, i;
};

inline int get_ind(const vector<int>& v, const int& x) {
    return lower_bound(all(v), x) - v.begin();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d", &n);

    vector<int> all_vals;
    vector<int> sorted_inds;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        all_vals.push_back(a[i]);
        sorted_inds.push_back(i);
    }

    sort(all(all_vals));
    all_vals.erase(unique(all(all_vals)), all_vals.end());

    sort(all(sorted_inds), [](const int& x, const int& y) {
            return a[x] < a[y];
    });

    int q;
    scanf("%d", &q);

    int l, r, k;
    vector<query> queries;
    for (int i = 0; i < q; ++i) {
        scanf("%d %d %d", &l, &r, &k);
        queries.push_back({l, r, k, i});
    }

    sort(all(queries), [](const query& q1, const query& q2) {
            return q1.k > q2.k;
    });

    int ptr = n - 1;
    for (const query& quer : queries) {
        while (ptr >= 0 and a[sorted_inds[ptr]] > quer.k) {
            update(sorted_inds[ptr]);
            --ptr;
        }

        ans[quer.i] = ask(quer.r) - ask(quer.l - 1);
    }

    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
