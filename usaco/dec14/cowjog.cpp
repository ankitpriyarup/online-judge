#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <set>
#include <queue>
#define MAX_N 100005
using namespace std;

long long N, T;
long long lane_pos[MAX_N];
long long lane_spd[MAX_N];

int main() {
    ifstream fin("cowjog.in");
    ofstream fout("cowjog.out");
    fin >> N >> T;
    long long pos, spd;
    memset(lane_pos, -1, sizeof(lane_pos));
    memset(lane_spd, -1, sizeof(lane_spd));

    int ans = 1;
    for (int i = 0; i < N; i++) {
        //cout << "Cow " << i << '\n';
        fin >> pos >> spd;
        for (int j = 0; j < MAX_N; j++) {
            //cout << "Trying lane " << j << '\n';
            if (lane_pos[j] < pos && (lane_pos[j] + lane_spd[j]*T < pos + spd*T)) {
                lane_pos[j] = pos;
                lane_spd[j] = spd;
                ans = max(ans, j + 1);
                break;
            }
        }
    }
    fout << ans << '\n';
    return 0;
}
