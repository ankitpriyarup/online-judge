#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX_N 100005

using namespace std;

int N, a[MAX_N], lis[MAX_N], lisb[MAX_N];

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> a[i];
    }
    lis[0] = 1;
    int best = 1;
    for(int i=1;i<N;i++) { //find all increasing subsegments
        lis[i] = (a[i] > a[i-1]) ? lis[i-1] + 1 : 1;
        best = max(best, (i < N-1 ? 1 : 0) + lis[i]);
    }
    lisb[N-1] = 1;
    for(int i=N-2;i>=0;i--) {
        lisb[i] = (a[i+1] > a[i]) ? lisb[i+1] + 1 : 1;
        best = max(best, (i > 0 ? 1 : 0) + lisb[i]);
    }
    if(N > 1) {
        best = max(best, 1+lis[N-2]);
        best = max(best, 1+lisb[1]);
    }
    for(int i=1;i<N-1;i++) { //see what changing i gets you
        if(a[i+1] - a[i-1] >= 2) {
            best = max(best, lis[i-1] + lisb[i+1] + 1);
        }
    }
    cout << best << '\n';
    return 0;
}
