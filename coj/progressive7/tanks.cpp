#include <cstdio>

using namespace std;

int main() {
    int N, Q, amt;
    int wells[1001];
    int filled[1001];

    while(!feof(stdin)) {
        int count = scanf("%d %d", &N, &Q);
        if(count != 2) break;
        for(int i=0;i<N;i++) {
            scanf("%d", &wells[i]);
        }
        filled[0] = 1;
        for(int i=1; i<N; i++) {
            filled[i] = filled[i-1] + wells[i];
        }
        for(int i=0;i<Q;i++) {
            scanf("%d", &amt);
            int j = N - 1;
            for(;filled[j] > amt &&j>=0;j--);
            if(i > 0) 
                printf(" ");
            printf("%d", j+1);
        }
        printf("\n");
    }
    return 0;
}

