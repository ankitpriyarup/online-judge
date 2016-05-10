#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

long long m;
int n1, n2;

long long amulus[61];
long long water[16];
long long ans[61];

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        cin >> m >> n1 >> n2;
        for (int i = 0; i < n1; ++i) 
            cin >> amulus[i];

        for (int i = 0; i < n2; ++i) 
            cin >> water[i];

        sort(amulus, amulus + n1);
        sort(water, water + n2);

        long long bestAm = 0LL;
        int realSize = 0;
        bool solved = false;

        for (int mask = 0; mask < (1 << n2); ++mask) {
            // find the amount of water used
            long long water_used = 0;
            for (int i = 0; i < n2; ++i) {
                if (mask & (1 << i)) {
                    water_used += water[i];
                }
            }

            long long remaining = m - water_used;
            //cout << "Trying with " << remaining << '\n';
            vector<long long> cur;
            int size = 0;
            for (int i = n1 - 1; i >= 0; --i) {
                if (amulus[i] <= remaining) {
                    cur.push_back(amulus[i]);
                    remaining -= amulus[i];
                    size += 1;
                }
            }

            if (remaining == 0 and (m - water_used) >= bestAm) {
                solved = true;
                realSize = size;
                bestAm = m - water_used;
                for (int i = 0; i < size; ++i) {
                    ans[i] = cur[i];
                }
            }
        }

        if (solved == true) {
            cout << "YES\n";
            if (realSize == 0) {
                cout << '\n';
            } else {
                cout << ans[realSize - 1];
                for (int i = realSize - 2; i >= 0; --i) {
                    cout << ' ' << ans[i];
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
