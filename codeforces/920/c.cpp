#include <cstdio>
#include <algorithm>

using namespace std;

constexpr int MAXN = 200005;
int n;
int a[MAXN];
char s[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }

    scanf("%s", s + 1);

    int j = 1;
    for (int i = 1; i <= n; ) {
        if (s[i] == '0') {
            ++i;
            j = i;
        } else {
            while (j < n and s[j] == '1')
                ++j;

            if (j < n and s[j] == '0')
                --j;

            sort(a + i, min(a + n + 1, a + j + 2));
            i = j + 1;
            j = i;
        }
    }

    bool safe = true;
    for (int i = 1; i <= n; ++i) {
        safe &= (a[i] == i);
    }

    printf("%s\n", safe ? "YES" : "NO");

    return 0;
}
