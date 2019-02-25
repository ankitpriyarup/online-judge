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
int n, energy;
int a[MAXN];

void read() {
    scanf("%d %d", &energy, &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    sort(a, a + n);
}

int simulate(int energ, int start, int end) {
    int ans = 0;
    for (int i = start; i <= end; ++i) {
        if (a[i] >= energ) {
            break;
        }

        energ -= a[i];
        ++ans;
    }

    return ans;
}

void solve(int case_num) {
    int cur_energy = energy;
    int start = 0;
    int end = n - 1;

    int ans = simulate(energy, start, end);
    // defeat start to get the energy of end
    while (start < end) {
        if (cur_energy <= a[start]) {
            break;
        }
        cur_energy -= a[start];
        cur_energy += a[end];
        ans = max(ans, simulate(cur_energy, start + 1, end - 1));

        ++start;
        --end;
    }

    printf("Case #%d: %d\n", case_num, ans); 
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
