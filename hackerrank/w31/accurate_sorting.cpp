#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
int n;
int a[MAXN];

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
        }

        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == i) {}
            else if (a[i + 1] == i and abs(a[i] - a[i + 1]) == 1) {
                swap(a[i + 1], a[i]);
            } else {
                valid = false;
                break;
            }
        }

        printf("%s\n", valid ? "Yes" : "No");
    }
    return 0;
}
