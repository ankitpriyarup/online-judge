#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 102;
const int MAXV = (1000 * MAXN + 2);
const int INF = 1e9;

int chunks[MAXN];

vector<int> parse() {
    int n;
    scanf("%d", &n);

    vector<int> v(MAXV, -1);

    for (int i = 0; i < n; ++i) {
        scanf("%d", chunks + i);
    }

    v[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = MAXV - 1; j >= 0; --j) {
            if (v[j] >= 0 and j + chunks[i] < MAXV) {
                if (v[j + chunks[i]] == -1 or v[j] + 1 < v[j + chunks[i]]) {
                    v[j + chunks[i]] = v[j] + 1;
                }
            }
        }
    }

    return v;
}

int main() {
    auto a = parse();
    auto b = parse();

    int ans = INF;
    for (int i = 1; i < MAXV; ++i) {
        if (a[i] > 0 and b[i] > 0) {
            ans = min(ans, a[i] + b[i]);
        }
    }

    if (ans == INF) {
        printf("%s\n", "impossible");
    } else {
        printf("%d\n", ans);
    }

    return 0;
}
