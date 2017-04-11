#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int n;
int a[31];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", a + i);
    }

    int needed = 1;
    double tape = 0;
    bool possible = false;
    double l1 = pow(2., -.25);
    double l2 = pow(2., -.75);

    for (int i = 1; i <= n; ++i) {
        if (a[i] >= needed) {
            possible = true;
            break;
        }

        needed -= a[i];
        tape += l2 * needed;
        needed *= 2;

        double temp = l1 / 2.0;
        l1 = l2;
        l2 = temp;
    }

    if (!possible)
        printf("impossible\n");
    else
        printf("%.9f\n", tape);
    return 0;
}
