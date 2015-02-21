#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int T, N, K;
char clockk[22];
char ckey[22];
int keys[22];

int main() {
    cin >> T;
    for (int casen = 0; casen < T; casen++) {
        cin >> N >> K;
        cin >> clockk;
        long ilock = strtol(clockk, NULL, 2);

        for (int i = 0; i < K; i++) {
            cin >> ckey;
            keys[i] = strtol(ckey, NULL, 2);
        }

        bool works = false;
        for (int mask = 0; mask < (1 << K); mask++) {
            long val = ilock;
            for (int j = 1, p = 0; j <= mask; j *= 2, p++) {
                if ((mask & j) > 0) {
                    val ^= keys[p]; 
                }
            }
            if (val == 0L) {
                works = true;
                break;
            }
        }
        cout << (works ? "YES" : "NO") << '\n';
    }
    return 0;
}
