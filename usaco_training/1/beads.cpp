/*
ID: rednano1
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

#define MAX_N 355

using namespace std;

char beads[MAX_N];
int N;

int main(){
    ifstream fin  ("beads.in");
    ofstream fout ("beads.out");

    fin >> N;
    fin >> beads;

    int best = 0;

    for (int i = 0; i < N; ++i) {
        char init = ' ';
        bool go = true;
        int j = i;
        int forw = 0;

        while (go) {
            if (beads[j] != 'w') {
                if (init == ' ') 
                    init = beads[j];
                else if (init != beads[j]) {
                    go = false;
                    break;
                }
            }

            j++;
            forw++;
            j %= N;
            if (forw >= N) {
                go = false;
                break;
            }
        }

        init = ' ';
        go = true;
        j = i - 1;
        int back = 0;
        while (go) {
            if (beads[j] != 'w') {
                if (init == ' ') 
                    init = beads[j];
                else if (init != beads[j]) {
                    go = false;
                    break;
                }
            }
            j--;
            back++;
            if (j < 0)
                j += N;
            if (back >= N) {
                go = false;
                break;
            }
        }
        best = max(best, forw + back);
    }
    fout << min(N, best) << endl;
    return 0;
}
