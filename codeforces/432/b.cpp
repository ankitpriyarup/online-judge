#include <cstdio>
#define MAX_N 100005
using namespace std;

int N;
int X[MAX_N], Y[MAX_N];
int homeColor[MAX_N];
int main() {
    scanf("%d", &N);
    for(int i=0;i<N;i++) {
        scanf("%d %d", &X[i], &Y[i]);
        homeColor[X[i]]++;
    }
    int home, away, d;
    for(int i=0;i<N;i++) {
        home = N-1;
        away = N-1;
        
        d = homeColor[Y[i]];
        home += d;
        away -= d;

        printf("%d %d\n", home, away);
    }
    return 0;
}
