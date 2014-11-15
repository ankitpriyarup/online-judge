#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int T, W, D, minn, maxx;
int comet[1001];
int main() {
    cin >> T;
    while (T-- > 0) {
        cin >> W >> D;
        for (int i = 0; i < W; i++) {
            cin >> comet[i];
        }
       
        int ans = 0;
        int gap = 10000000;
        for (int start = 0; start + D <= W; start++) {
            minn = comet[start];
            maxx = comet[start];
            for(int i = start; i < start + D; i++) {
                minn = min(minn, comet[i]);
                maxx = max(maxx, comet[i]);
            }
            if (maxx - minn < gap) {
                ans = start;
                gap = maxx - minn;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
