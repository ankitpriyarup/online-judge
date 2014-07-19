/* For whoever's reading this: this strategy is wrong and does not work!!!!
 * I got very lucky and got the small case correct
 */

#include <iostream>
#define MAX_N 11
using namespace std;
int T, N;
double naomi[MAX_N], ken[MAX_N];
int main() {
    cin >> T;
    for(int ll=1;ll<=T;ll++) {
        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> naomi[i];
        }
        for(int i=0;i<N;i++) {
            cin >> ken[i];
        }
        sort(naomi, naomi + N);
        sort(ken, ken + N);
        /*
        puts("Naomi: ");
        for(int i=0;i<N;i++) {
            printf("%.3f ", naomi[i]);
        }
        puts("\nKen: ");
        for(int i=0;i<N;i++) {
            printf("%.3f ", ken[i]);
        }
        putchar('\n');
        */
        //both arrays are sorted
        /*decietful strat: naomi burns her lowest blocks 
         * until she's guaranteed a point. then she takes the point. 
         * rinse and repeat.
         */
        //naomi's only looking at her lowest and highest blocks 
        int nl = 0, nr = N-1;
        //easy access to ken's lowest and highest blocks
        int kl = 0, kr = N-1;
        int cheat = 0;
        for(int i=0;i<N;i++) {
            //naomi's only guaranteed a point if her highest block is higher than ken's highest
            if(naomi[nr] > ken[kr]) {
                cheat++;
                nr--;
                kr--;
            } else {
                //she burns ken's best block
                nl++;
                kr--;
            }
        }
        //in real war, naomi has no idea what ken's blocks are.
        int war = 0;
        bool used[MAX_N] = {0}; //has ken used block i?
        kl = 0; //easy access to ken's smallest unused block;
        for(int i=0; i<N; i++) {
            double block = naomi[i];
            //find the smallest block ken can use to beat it
            int j = 0;
            for(;j<N;j++) {
                if(ken[j] > block) break;
            }
            while(j < N && used[j]) j++;
            if(j == N) {//no block found
                war++;
                //burn the smallest block
                used[kr] = true;
                kr++;
                while(used[kr]) kr++;
            } else {
                used[j] = true;
                if(j == kr) {
                    kr++;
                    while(used[kr]) kr++;
                }
            }
        }
        printf("Case #%d: %d %d\n", ll, cheat, war);
    }
    return 0;
}
