#include <cstdio>
 
using namespace std;
 
int main(){
    int T, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        int z = 0;
        for(int i=5; i <= N; i *= 5) {
            z += N / i;
        }
        printf("%d\n", z);
    }
    return 0;
}
