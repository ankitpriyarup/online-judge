#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vpii = vector<pii>;

int n, m;

int main() {
    scanf("%d %d", &n, &m);

    vpii v;
    int a, s;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &s);
        v.push_back({a, 1});
        v.push_back({a + s, -1});
    }

    sort(begin(v), end(v));

    multiset<int> safe;

    int ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (v[i].second == 1) {
            // printf("Finding station for job starting at %d\n", v[i].first);
            while (!safe.empty() and *(safe.begin()) < v[i].first) {
                safe.erase(safe.begin());
            }

            if (safe.empty()) {
                // printf("Nothing found\n");
                ++ans;
            } else {
                // printf("Using workstation safe to %d\n", *safe.begin());
                safe.erase(safe.begin());
            }
        } else {
            // printf("Finished job at %d inserting safe to %d\n", v[i].first, v[i].first + m);
            safe.insert(v[i].first + m);
        }
    }

    printf("%d\n", n - ans);
    return 0;
}
