/*
ID: rednano1
PROG: stall4
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

vector<int> graph[202];
int cow_to_stall[202];
int stall_to_cow[202];
bool seen[202];
int N, M;

int augment(int start) {
    for (int i = 0; i < (int)graph[start].size(); ++i) {
        int m = graph[start][i];
        if (!seen[m] and stall_to_cow[m] == -1) {
            seen[m] = true;
            cow_to_stall[start] = m;
            stall_to_cow[m] = start;
            return true;
        }
    }

    for (int i = 0; i < (int)graph[start].size(); ++i) {
        int m = graph[start][i];
        if (!seen[m]) {
            seen[m] = true;
            if (augment(stall_to_cow[m])) {
                cow_to_stall[start] = m;
                stall_to_cow[m] = start;
                return true;
            }
        }
    }

    return false;
}

int match() {
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        memset(seen, 0, sizeof(seen));
        if (augment(i)) {
            ans++;
        }
    }

    return ans;
}

int main() {
    ifstream fin("stall4.in");
    ofstream fout("stall4.out");

    fin >> N >> M;

    memset(graph, 0, sizeof(graph));

    int S, x;
    for (int i = 0; i < N; ++i) {
        fin >> S;
        for (int j = 0; j < S; ++j) {
            fin >> x;
            graph[i].push_back(x - 1);
        }
    }

    fin.close();

    memset(cow_to_stall, -1, sizeof(cow_to_stall));
    memset(stall_to_cow, -1, sizeof(stall_to_cow));
    fout << match() << '\n';

    return 0;
}
