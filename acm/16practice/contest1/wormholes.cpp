#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int W, S;
vector<pair<int, int> > wormholes;
vector<int> years;

int main() {
    int T;
    int D, A, M;
    int query;

    cin >> T;
    while (T-- > 0) {
        cin >> W;
        wormholes.clear();
        years.clear();

        for (int i = 0; i < W; ++i) {
            cin >> D >> A;
            wormholes.push_back(make_pair(D, A));
            years.push_back(D);
            years.push_back(A);
        }

        cin >> S;
        years.push_back(S);

        sort(years.begin(), years.end());

        bellman_ford();

        cin >> M;
        while (M-- > 0) {
            cin >> query;
        }
    }

    return 0;
}
