#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 500005;
int n, m;
int a[MAXN];
vector<int> all_nums;

long long f_tree[MAXN];

long long query(const int& x) {
    long long ans = 0LL;
    for (int i = x; i > 0; i -= (i & -i)) {
        ans += f_tree[i];
    }

    return ans;
}

void update(const int& x, const long long& v) {
    for (int i = x; i < MAXN; i += (i & -i)) {
        f_tree[i] += v;
    }
}

inline int get_ind(const int& v) {
    return 1 + (lower_bound(all_nums.begin(), all_nums.end(), v) - all_nums.begin());
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        all_nums.push_back(a[i]);
    }
    
    sort(all_nums.begin(), all_nums.end());
    all_nums.erase(unique(all_nums.begin(), all_nums.end()), all_nums.end());
    
    for (int i = 0; i < n; ++i) {
        a[i] = get_ind(a[i]);
    }
    
    memset(f_tree, 0, sizeof(f_tree));
    long long cur = 0LL;
    for (int i = 0; i < m; ++i) {
        // count how many are greater than you
        int greater = i - query(a[i]);
        cur += greater;
        update(a[i], 1);
    }
    
    long long ans = cur;
    
    for (int i = m; i < n; ++i) {
        cur -= query(a[i - m] - 1);
        update(a[i - m], -1);

        int greater = (m - 1) - query(a[i]);
        cur += greater;
        
        update(a[i], 1);
        
        ans += cur;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
