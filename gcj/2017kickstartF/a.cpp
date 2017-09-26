#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;

constexpr int MAXN = 100005;
int n;
int a[MAXN];
bool used[MAXN];
set<int> all_vals;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    all_vals.clear();
    for (int i = 1; i <= n; ++i) {
        all_vals.insert(i);
    }

    memset(used, false, sizeof(used));
}

void solve(int case_num) {
    bool valid = true;

    int len = n;
    while (true) {
        if (len <= 2) {
            valid = false;
            break;
        }

        int target_ind = (len - 1) / 2;
        int seen = 0;
        int ind = 0;

        while (seen < target_ind) {
            if (!used[ind]) {
                ++seen;
            }
            ++ind;
        }

        while (used[ind]) {
            ++ind;
        }

        int val = a[ind];
        if (val == *(all_vals.begin())) {
            used[ind] = true;
            all_vals.erase(all_vals.begin());
        } else if (val == *(all_vals.rbegin())) {
            used[ind] = true;

            auto ptr = all_vals.end();
            ptr = prev(ptr);

            all_vals.erase(ptr);
        } else {
            break;
        }

        --len;
    }

    printf("Case #%d: %s\n", case_num, !valid ? "YES" : "NO");
}

int main() {
    int T;
    scanf("%d", &T);
    for (int case_num = 1; case_num <= T; ++case_num) {
        read();
        solve(case_num);
    }

    return 0;
}
