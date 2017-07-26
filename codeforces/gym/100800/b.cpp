#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef long double ld;

const ld PI = acos(-1);

int n;
ld g;

ld solve(const vector<pair<int, int> >& inp, int start) {
    ld v = 0.0L;
    for (int i = start; i < n; ++i) {
        ld c = cos(PI * inp[i].second / 180.0L);
        v = sqrt((v * v) + (2.0L * g * c * inp[i].first));
    }

    return v;
}

int main() {
    scanf("%d %Lf\n", &n, &g);

    vector<pair<int, int> > input;
    for (int i = 0; i < n; ++i) {
        int d, theta;
        scanf("%d %d", &d, &theta);

        input.push_back({d, theta});
    }

    for (int i = 0; i < n; ++i) {
        ld ans = solve(input, i);
        printf("%.12Lf\n", ans);
    }

    return 0;
}
