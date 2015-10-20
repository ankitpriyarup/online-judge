#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
int points[505][2];
int main() {
    int T, N, S;
    set<int> xs;
    set<int> ys;
    cin >> T;
    for(int ttt=0;ttt<T;ttt++) {
        cin >> N >> S;
        xs.clear();
        ys.clear();

        for(int i=0;i<N;i++) {
            cin >> points[i][0];
            cin >> points[i][1];
            xs.insert(points[i][0]);
            ys.insert(points[i][1]);
        }
        int best = 0;
        for(set<int>::iterator xit = xs.begin(); xit != xs.end(); xit++) {
            for(set<int>::iterator yit = ys.begin(); yit != ys.end(); yit++) {
                int xmin = *xit;
                int ymin = *yit;
                int xmax = xmin + S;
                int ymax = ymin + S;
                int count = 0;
                for(int i=0;i<N;i++) {
                    if(xmin <= points[i][0] && points[i][0] <= xmax
                    && ymin <= points[i][1] && points[i][1] <= ymax) {
                        count++;
                    }
                }
                best = max(best, count);
            }
        }
        cout << best << '\n';
    }
    return 0;
}
