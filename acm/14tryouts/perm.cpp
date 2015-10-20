#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
int p[1010], seen[1010];
int main() {
    int T, N, value, output;
    cin >> T;
    for(int ttt=0;ttt<T;ttt++) {
        cin >> N >> value >> output;
        for(int i=1;i<=N;i++) {
            cin >> p[i];
            seen[i] = false;
        }
        int v = value;
        int k = 0;
        while(!seen[v] && v != output) {
            seen[v] = true;
            v = p[v];
            k++;
        }
        if(v == output) {
            cout << k << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
