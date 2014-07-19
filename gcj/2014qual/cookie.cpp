#include <iostream>
#define MAX_N 1000000
using namespace std;
int T;
double C, F, X;
double fcost[MAX_N], xcost[MAX_N], total[MAX_N];
int main() {
    cin >> T;
    for(int ll=1;ll<=T;ll++) {
        cin >> C >> F >> X;
        fcost[0] = 0.0;
        xcost[0] = X/2;
        bool trying = true;
        //printf("Index: %d | fcost: %.3f | xcost: %.3f | total: %.6f\n", 0, fcost[0], xcost[0], fcost[0]+xcost[0]);
        double ans = fcost[0] + xcost[0];
        for(int i = 1; trying && i < MAX_N ; i++) {
            fcost[i] = fcost[i-1] + C/(2+F*(i-1));
            xcost[i] = X/(2+F*i);
            total[i] = fcost[i] + xcost[i];
            ans = min(ans, total[i]);
            //printf("Index: %d | fcost: %.3f | xcost: %.3f | total: %.6f\n", i, fcost[i], xcost[i], fcost[i]+xcost[i]);
            trying = !(i == 1 && total[1] > total[0]);
            trying = !(i > 1 && total[i-2] > total[i-1] && total[i-1] < total[i]);
        }
        printf("Case #%d: %.7f\n", ll, ans);
    }
    return 0;
}
