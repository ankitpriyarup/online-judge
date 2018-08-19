#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000006;

namespace uf {
    int uf[MAXN];

    void init(const int& n) {
        for (int i = 0; i <= n; ++i)
            uf[i] = i;
    }

    int find(int x) {
        return uf[x] = uf[x] == x ? x : find(uf[x]);
    }

    int merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return false;

        uf[xr] = yr;
        return true;
    }
}

int main() {
    int n, q;
    scanf(" %d %d", &n, &q);
    uf::init(n);

    char op;
    int u, v;
    while (q-- > 0) {
        scanf(" %c %d %d", &op, &u, &v);
        if (op == '=') {
            uf::merge(u, v);
        } else {
            printf("%s\n", uf::find(u) == uf::find(v) ? "yes" : "no");
        }
    }

    return 0;
}
