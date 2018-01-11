#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 100005;

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
};

int main() {
    int n;
    scanf("%d", &n);

    vector<pair<int, int> > a;
    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a.push_back({x, i});
    }

    vector<pair<int, int> > b(begin(a), end(a));
    sort(begin(b), end(b));

    uf::init(n);
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            uf::join(a[i].second, b[i].second);
        }
    }

    map<int, vector<int> > out;
    for (int i = 0; i < n; ++i) {
        out[uf::find(i)].push_back(i);
    }

    printf("%d\n", out.size());
    for (auto& entry : out) {
        printf("%d", entry.second.size());
        for (auto& x : entry.second) {
            printf(" %d", x + 1);
        }

        printf("\n");
    }

    return 0;
}
