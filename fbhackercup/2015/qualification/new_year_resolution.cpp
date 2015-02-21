#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <queue>
using namespace std;

int gp, gc, gf;
int T, N;
int foods[21][3];

bool brute_force() {
    int MAX = (1 << N);
    for (int i = 1; i < MAX; i++) {
        int p = 0;
        int c = 0;
        int f = 0;
        for (int j = 0, x = 1; j < N; j++, x <<= 1) {
            if (i & x) {
                p += foods[j][0];
                c += foods[j][1];
                f += foods[j][2];
            }
        }

        if (p == gp && c == gc && f == gf) {
            return true;
        }
    }
    return false;
}

bool solve() {
    return brute_force();
}

int main() {
    cin >> T;
    for (int case_num = 1; case_num <= T; case_num++) {
        int gpsum = 0;
        int gcsum = 0;
        int gfsum = 0;

        cin >> gp >> gc >> gf;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> foods[i][0] >> foods[i][1] >> foods[i][2];
            gpsum += foods[i][0];
            gcsum += foods[i][1];
            gfsum += foods[i][2];
        }
        
        //easy quick checks
        bool works = !(gpsum < gp || gcsum < gc || gfsum < gf);
        if (gpsum == gp || gcsum == gc || gfsum == gf) {
            works &= (gpsum == gp && gcsum == gc && gfsum == gf);
        }

        if (works) {
            works = solve();
        }

        cout << "Case #" << case_num << ": " << (works ? "yes" : "no") << '\n'; 
    }
    return 0;
}
