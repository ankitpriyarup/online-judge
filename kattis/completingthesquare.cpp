#include <cstdio>
#include <utility>

using namespace std;

typedef pair<long long, long long> pt;

long long mag(pt p) {
    return 1LL * p.first * p.first + 1LL * p.second * p.second;
}

pt add(pt a, pt b) {
    return pt { a.first + b.first, a.second + b.second };
}

pt sub(pt a, pt b) {
    return pt { a.first - b.first, a.second - b.second };
}

pt pts[3];

int main() {
    long long x, y;
    for (int i = 0; i < 3; ++i) {
        scanf("%lld %lld", &x, &y);
        pts[i] = {x, y};
    }

    for (int i = 0; i < 3; ++i) {
        pt a = sub(pts[(i + 1) % 3], pts[i]);
        pt b = sub(pts[(i + 2) % 3], pts[i]);

        if (mag(a) == mag(b)) {
            pt ans = add(pts[i], a);
            ans = add(ans, b);

            printf("%lld %lld\n", ans.first, ans.second);
            return 0;
        }
    }

    return 0;
}
