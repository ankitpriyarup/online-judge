#include <cstdio>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    int r, e, c;
    while (T-- > 0) {
        scanf("%d %d %d", &r, &e, &c);
        if (r < e - c) {
            printf("advertise\n");
        } else if (r == e - c) {
            printf("does not matter\n");
        } else {
            printf("do not advertise\n");
        }
    }

    return 0;
}
