//Problem        : Funny Elevators
//Language       : C++11
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int F, E, A, B;
bool reachable[22][2002];
int elevators[22][2];
int visited[22];
bool found = false; 

void dfs(int elev_index) {
    if (reachable[elev_index][B]) found = true;

    if (visited[elev_index]) return;
    visited[elev_index] = true;

    for (int j = 0; j < F; ++j) {
        for (int i = 0; i < E; ++i) {
            if (reachable[elev_index][j] && reachable[i][j]) {
                dfs(i);
            }
        }
    }
}

int main() {
    cin >> F >> E >> A >> B;

    memset(reachable, 0, sizeof(reachable));
    for (int i = 0; i < E; ++i) {
        cin >> elevators[i][0] >> elevators[i][1];
        for (int j = elevators[i][1]; j < F; j += elevators[i][0]) {
            reachable[i][j] = 1;
        }
    }

    for (int i = 0; i < E; ++i) {
        if (reachable[i][A]) {
            memset(visited, 0, sizeof(visited));
            dfs(i);
        }
    }

    cout << found << '\n';

    return 0;
}
