#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

constexpr int MAXN = 100005;
char a[MAXN], b[MAXN];
int n, m;

int main() {
    scanf("%s", a);
    scanf("%s", b);
    n = strlen(a);
    m = strlen(b);

    int ans = m;

    int prefix = 0;
    while (prefix < n and prefix < m and a[prefix] == b[prefix]) {
        ++prefix;
        --ans;
    }

    int ap = n - 1;
    int bp = m - 1;

    while (ap >= prefix and bp >= prefix and a[ap] == b[bp]) {
        --ans;
        --ap;
        --bp;
    }

    printf("%d\n", max(0, ans));

    return 0;
}
