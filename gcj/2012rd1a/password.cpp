#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX_A 100003
using namespace std;

int main() {
    int T, A, B;
    double P[MAX_A];
    double dp[MAX_A];
    scanf("%d", &T);
    for(int ll=1;ll<=T;ll++) {
        scanf("%d %d", &A, &B);
        for(int i=0;i<A;i++) {
            scanf("%lf", &P[i]);
        }
        dp[0] = 1; //dp[i] = the probability that the numbers up to but not including i are ok
        for(int i=1;i<=A;i++) {
            dp[i] = dp[i-1]*P[i-1];
        }
        //finish typing, then enter
        double ans = dp[A]*(B - A + 1) + (1 - dp[A])*(B - A + 1 + B + 1);

        //press enter, then retype
        ans = min(ans, (double)(B + 2));

        //try deleting A-i characters
        double finishProb;
        for(int i = 0; i < A; i++){
            finishProb = dp[A-i]*(B - A + i + i + 1) + (1 - dp[A-i])*(B - A + i + i + 1 + B + 1);
            ans = min(ans, finishProb);
        }
        printf("Case #%d: %.6f\n", ll, ans);
    }
    return 0;
}
