#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000006;
int n;
long long c, w, b;
int d[MAXN];

bool works(int start, int end) {
    long long dist = d[end] - d[start];
    return dist * w + c * (end - start + 1LL) <= b;
}

int main() {
    scanf("%d %lld %lld %lld", &n, &c, &w, &b);
    for (int i = 0; i < n; ++i) {
        scanf("%d", d + i);
    }

    // say you turn the battery on at i
    // say you catch k pokemon
    // Then the battery used is w * (d[i + k] - d[i]) + c * k
    int end = 0;
    int ans = 0;
    for (int start = 0; start < n; ++start) {
        end = max(start, end);
        while (end < n and works(start, end)) {
            ++end;
        }

        ans = max(ans, end - start);
    }

    printf("%d\n", ans);

    return 0;
}
