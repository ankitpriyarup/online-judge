#include <cstdio>

using namespace std;

const int MAXN = 10004;
int h, w, n;
int a[MAXN];

int main() {
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);

    int row = 0;
    int filled = 0;
    bool angry = false;
    for (int i = 0; row < h and !angry and i < n; ++i) {
        filled += a[i];
        if (filled > w) {
            angry = true;
        } else if (filled == w) {
            filled = 0;
            ++row;
        }
    }

    if (angry)
        printf("NO");
    else
        printf("YES");
    return 0;
}
