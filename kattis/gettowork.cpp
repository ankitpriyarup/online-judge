#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 102;
int n;
int dest;
int num_employees;

int population[MAXN];
int ans[MAXN];
vector<int> drivers[MAXN];

int main() {
    int T;
    scanf("%d", &T);

    for (int case_num = 1; case_num <= T; ++case_num) {
        scanf("%d %d", &n, &dest);
        scanf("%d", &num_employees);

        for (int town = 1; town <= n; ++town) {
            population[town] = 0;
            drivers[town].clear();
        }

        int h, p;
        for (int i = 0; i < num_employees; ++i) {
            scanf("%d %d", &h, &p);
            ++population[h];
            if (p > 0) {
                drivers[h].push_back(p);
            }
        }

        bool possible = true;
        for (int town = 1; town <= n; ++town) {
            if (town == dest) continue;

            sort(drivers[town].begin(), drivers[town].end());

            ans[town] = 0;
            while (!drivers[town].empty() and population[town] > 0) {
                population[town] -= drivers[town].back();
                drivers[town].pop_back();
                ++ans[town];
            }

            if (population[town] > 0) {
                possible = false;
                break;
            }
        }

        ans[dest] = 0;
        printf("Case #%d: ", case_num);
        if (possible) {
            for (int i = 1; i <= n; ++i) {
                printf("%d ", ans[i]);
            }
            puts("");
        } else {
            puts("IMPOSSIBLE");
        }
    }

    return 0;
}
