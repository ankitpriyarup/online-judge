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

int dim;
int l[10];

vector<int> unpack(int x) {
    vector<int> res(dim);
    for (int i = dim - 1; i >= 0; --i) {
        res[i] = x % l[i];
        x /= l[i];
    }

    return res;
}

int pack(const vector<int>& v) {
    int res = 0;
    int base = 1;
    for (int i = dim - 1; i >= 0; --i) {
        int x = v[i];
        res += x * base;
        base *= l[i];
    }

    return res;
}

constexpr int MAXN = 2e6 + 6;
ll vals[MAXN];
ll dist[MAXN];
int previous[MAXN];
int inds[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &dim);
    int total = 1;
    for (int i = 0; i < dim; ++i) {
        scanf("%d", l + i);
        total *= l[i];
    }

    ll least = 1e15;
    ll most = -1;
    int start_ind = 0;
    int end_ind = 0;
    for (int i = 0; i < total; ++i) {
        scanf("%lld", &vals[i]);

        /*
        printf("%d = ", i);
        for (int x : unpack(i)) {
            printf(" %d", x);
        }
        printf("\n");
        */

        if (vals[i] < least) {
            end_ind = i;
            least = vals[i];
        }

        if (vals[i] >= most) {
            start_ind = i;
            most = vals[i];
        }
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push({vals[start_ind], start_ind});

    memset(dist, -1, sizeof(dist));
    dist[start_ind] = vals[start_ind];

    ll cur; int u;
    while (!pq.empty()) {
        tie(cur, u) = pq.top();
        pq.pop();

        if (dist[u] != cur)
            continue;

        if (u == end_ind) {
            break;
            return 0;
        }

        vector<int> v = unpack(u);
        /*
        printf("%d unpacked to", u);
        for (int x : v)
            printf(" %d", x);
        printf("\n");
        */

        for (int d = 0; d < dim; ++d) {
            for (int dx = -1; dx <= 1; dx += 2) {
                v[d] += dx;

                if (0 <= v[d] and v[d] < l[d]) {
                    int ind = pack(v);
                    ll new_dist = cur + vals[ind];
                    if (dist[ind] == -1 or new_dist < dist[ind]) {
                        dist[ind] = new_dist;
                        previous[ind] = u;
                        pq.push({dist[ind], ind});
                    }
                }

                v[d] -= dx;
            }
        }
    }

    printf("%lld\n", dist[end_ind]);
    int p = 0;
    u = end_ind;
    while (u != start_ind) {
        inds[p++] = u;
        u = previous[u];
    }

    inds[p] = start_ind;
    for (int i = p; i >= 0; --i) {
        vector<int> v = unpack(inds[i]);
        for (int j = 0; j < dim; ++j) {
            printf("%d%c", v[j], " \n"[j == dim - 1]);
        }
    }

    return 0;
}
