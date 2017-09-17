#include <cstdio>

using namespace std;

int main() {
    int n, w, h;
    scanf("%d %d %d", &n, &w, &h);

    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x * x <= w * w + h * h) {
            printf("DA\n");
        } else {
            printf("NE\n");
        }
    }
}
