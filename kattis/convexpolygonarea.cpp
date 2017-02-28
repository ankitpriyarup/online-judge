#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<long long, long long> pt;

int n;
vector<pt> pts;

int main() {
    int T, x, y;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        pts.clear();
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &x, &y);
            pts.push_back(pt(x, y));
        }

        long long area = 0LL;
        for (int i = 0; i < n; ++i) {
            int ni = (i + 1) % n;
            area += 1LL * pts[i].first * pts[ni].second;
            area -= 1LL * pts[i].second * pts[ni].first;
        }

        bool dec = area % 2;
        printf("%lld", area / 2);
        if (dec) {
            printf(".5");
        }
        printf("\n");
    }

    return 0;
}
