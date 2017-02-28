#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    long long a;
    scanf("%lld", &a);
    long double s = sqrt(a);

    printf("%.12Lf\n", 4.0L * s);
    return 0;
}
