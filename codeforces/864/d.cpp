#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

constexpr int MAXN = 200005;
int n;
int a[MAXN];
int b[MAXN];
bool used[MAXN];
vector<int> pos[MAXN];

int fixer = 0;
void fix(int ind) {
    if (b[ind] != 0)
        return;

    ++fixer;
    b[ind] = a[ind];
    used[a[ind]] = true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = n; i >= 1; --i) {
        pos[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        if (pos[i].size() == 1) {
            int ind = pos[i].back();
            pos[i].pop_back();
            fix(ind);
        }
    }

    set<int> pq;
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 0) {
            pq.insert(i);
        }
    }

    for (int i = 1; i <= n; ++i) {
        // printf("Finding a place for %d\n", i);
        if (used[i])
            continue;

        if (pos[i].empty()) {
            // find the leftmost free spot
            while (b[*pq.begin()] != 0) {
                pq.erase(pq.begin());
            }

            int ind = *pq.begin();
            pq.erase(pq.begin());

            // printf("Doesn't exist, using %d\n", ind);

            b[ind] = i;
            used[i] = true;

            int old_val = a[ind];
            while (!pos[old_val].empty() and b[pos[old_val].back()] != 0) {
                pos[old_val].pop_back();
            }

            if (!used[old_val] and pos[old_val].size() == 1) {
                int ind2 = pos[old_val].back();
                pos[old_val].pop_back();
                fix(ind2);
            }
        } else {
            // use the first thing available
            while (b[pos[i].back()] != 0) {
                pos[i].pop_back();
            }
            int ind = pos[i].back();
            pos[i].pop_back();
            fix(ind);
        }
    }

    printf("%d\n", n - fixer);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}
