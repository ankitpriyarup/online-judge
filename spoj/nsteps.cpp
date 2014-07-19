#include <cstdio>
 
using namespace std;
 
int main(){
    int N, x, y;
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &x, &y);
        if(x == 0 && y == 0) {
            printf("%d\n", 0);
        } else if(y != x && y != x - 2) {
            printf("No Number\n");
        } else {
            int ans;
            if(x % 2 == 0) {
                ans = (y == x) ? 2*x : 2*x - 2;
            } else {
                ans = (y == x) ? 2*x - 1 : 2*x - 3;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
