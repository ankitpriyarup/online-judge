#include <cstdio>
#include <algorithm>
#include <cmath>

#define PI 3.141592653589793238

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int n;
        scanf("%d", &n);

        int x[n], y[n];
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", x + i, y + i);
        }

        bool success = true;
        for (int i = 0; i < n; ++i)
        {
            int a = i;
            int b = (i + 1) % n;
            int c = (i + 2) % n;

            // x' = cos(angle) * x + -sin(angle) * y
            // y' = sin(angle) * x +  cos(angle) * y
            //

            // (x, y) 
            long double angle = -atan2(y[b], x[b]);
            
            long double x1 = cos(angle) * x[a] + -sin(angle) * y[a];
            long double y1 = sin(angle) * x[a] +  cos(angle) * y[a];

            long double x2 = cos(angle) * x[b] + -sin(angle) * y[b];
            long double y2 = sin(angle) * x[b] +  cos(angle) * y[b];

            long double x3 = cos(angle) * x[c] + -sin(angle) * y[c];
            long double y3 = sin(angle) * x[c] +  cos(angle) * y[c];

            success &= (y1 <= 0 && y3 >= 0) || (y1 >= 0 && y3 <= 0);
            //printf("Angle: %f\t(%f, %f), (%f, %f), (%f, %f)\n", angle * 180.0 / PI, x1, y1, x2, y2, x3, y3);
        }

        printf("%s\n", (success ? "YES" : "NO"));
    }
    return 0;
}
