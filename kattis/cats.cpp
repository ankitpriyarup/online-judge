#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

const int MAXN = 2002;

namespace uf {
    int uf[MAXN];

    void init(const int& n) {
        for (int i = 0; i <= n; ++i)
            uf[i] = i;
    }

    int find(int x) {
        int p = uf[x];
        if (uf[p] != p)
            p = find(p);

        return uf[x] = p;
    }

    bool join(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return false;

        if (rand() % 2)
            swap(xr, yr);

        uf[xr] = yr;
        return true;
    }
}

typedef tuple<int, int, int> edge;
vector<edge> edges;

int main() {
    int T;
    scanf("%d", &T);
    int m, c;
    while (T-- > 0) {
        scanf("%d %d", &m, &c);
        uf::init(c);

        edges.clear();
        int u, v, d;
        for (int i = 0; i < c; ++i) {
            for (int j = i + 1; j < c; ++j) {
                scanf("%d %d %d", &u, &v, &d);
                edges.push_back(make_tuple(d, u, v));
            }
        }

        sort(edges.begin(), edges.end());
        int cost = 0;
        for (const edge& e : edges) {
            if (uf::join(get<1>(e), get<2>(e))) {
                cost += get<0>(e);
            }
        }

        printf("%s\n", cost + c <= m ? "yes" : "no");
    }
}
