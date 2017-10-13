#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <random>

using namespace std;

constexpr int MAXN = 50004;
constexpr int SEEDS = 500;

int n, start, x;
bool used[MAXN];
int val[MAXN], link[MAXN];

int queries = 0;
int below = -1;
int above = -1;

void query(int ind) {
    if (used[ind]) return;

    ++queries;
    printf("? %d\n", ind);
    fflush(stdout);
    scanf("%d %d", val + ind, link + ind);
    used[ind] = true;

    if (val[ind] < x) {
        below = (below == -1 or val[below] < val[ind]) ? ind : below;
    } else {
        above = (above == -1 or val[ind] < val[above]) ? ind : above;
    }
}

int main() {
    scanf("%d %d %d", &n, &start, &x);
    vector<int> v;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
    }

    shuffle(begin(v), end(v), default_random_engine(0xc4f3b3b3));

    memset(used, false, sizeof(used));
    below = above = -1;

    int ptr = 0;
    for (int i = 0; i < SEEDS; ++i) {
        while (ptr < v.size() and used[v[ptr]]) {
            ++ptr;
        }

        if (ptr >= v.size())
            break;

        query(v[ptr]);
    }

    if (below == -1 and !used[start]) {
        query(start);
    }

    if (below == -1) {
        printf("! %d\n", val[start]);
        fflush(stdout);
        return 0;
    }

    int ind = below;
    while (queries < 1990 and val[ind] < x) {
        ind = link[ind];
        if (ind <= 0)
            break;

        query(ind);
        if (val[ind] >= x) {
            break;
        }
    }

    printf("! %d\n", above == -1 ? -1 : val[above]);
    fflush(stdout);

    return 0;
}
