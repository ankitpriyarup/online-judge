#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int N, K;
    cin >> N;

    while (true) {
        if (N == 0) {
            break;
        }

        cin >> K;
        K *= N;
        K *= N - 1;
        K /= 2;
        int wins[N];
        int loss[N];
        memset(wins, 0, sizeof(wins));
        memset(loss, 0, sizeof(loss));

        int p1, p2;
        string m1, m2;
        for (int i = 0; i < K; ++i) {
            cin >> p1 >> m1 >> p2 >> m2;
            p1--;
            p2--;
            if (m1 == m2) {
                continue;
            }

            if ((m1[0] == 'r' && m2[0] == 's') || (m1[0] == 'p' && m2[0] == 'r') || (m1[0] == 's' && m2[0] == 'p')) {
                wins[p1]++;
                loss[p2]++;
            } else {
                wins[p2]++;
                loss[p1]++;
            }
        }
        
        for (int i = 0; i < N; ++i) {
            //printf("i: %d, wins: %d, loss: %d\n", i, wins[i], loss[i]);
            if (wins[i] + loss[i] == 0) {
                printf("-\n");
            } else {
                printf("%0.3f\n", ((double) wins[i]) / (wins[i] + loss[i]));
            }
        }

        cin >> N;

        if (N != 0) {
            printf("\n");
        }
    }
    return 0;
}
