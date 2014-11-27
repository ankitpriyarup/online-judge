#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <utility>

using namespace std;
int N;
char names[100001][2][55];
int p[100001];
int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> names[i][0] >> names[i][1];
    }
    for(int i=0;i<N;i++) {
        cin >> p[i];
        p[i]--;
    }
    
    int lastpos = strcmp(names[p[0]][0], names[p[0]][1]) < 0 ? 0 : 1;
    bool works = true;
    for(int i=1;i<N;i++) {
        if(strcmp(names[p[i-1]][lastpos], names[p[i]][0]) > 0
         && strcmp(names[p[i-1]][lastpos], names[p[i]][1]) > 0) {
            works = false;
            break;
        } else if(strcmp(names[p[i-1]][lastpos], names[p[i]][0]) < 0
         && strcmp(names[p[i-1]][lastpos], names[p[i]][1]) > 0) {
            lastpos = 0;
        } else if(strcmp(names[p[i-1]][lastpos], names[p[i]][0]) > 0
         && strcmp(names[p[i-1]][lastpos], names[p[i]][1]) < 0) {
            lastpos = 1;
        } else {
            lastpos = strcmp(names[p[i]][0], names[p[i]][1]) < 0 ? 0 : 1;
        }
    }
    if(works) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
