/*
ID: rednano1
PROG: shuttle
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

string cur, target;
vector<int> solution;
int n;

bool dfs() {
    if (cur == target) {
        return true;
    }

    // find the space
    int space_pos = cur.find(' ');
    // two before
    int ind = space_pos - 2;
    if (ind >= 0 and cur[ind] == 'W' and cur[ind + 1] == 'B') {
        swap(cur[ind], cur[space_pos]);
        if (dfs()) {
            solution.push_back(ind);
            return true;
        }
        swap(cur[ind], cur[space_pos]);
    }

    // one before
    ind = space_pos - 1;
    if (ind >= 0 and cur[ind] == 'W') {
        swap(cur[ind], cur[space_pos]);
        if (dfs()) {
            solution.push_back(ind);
            return true;
        }
        swap(cur[ind], cur[space_pos]);
    }

    // one after
    ind = space_pos + 1;
    if (ind < 2*n + 1 and cur[ind] == 'B') {
        swap(cur[ind], cur[space_pos]);
        if (dfs()) {
            solution.push_back(ind);
            return true;
        }
        swap(cur[ind], cur[space_pos]);
    }
 
    // two after
    ind = space_pos + 2;
    if (ind < 2*n + 1 and cur[ind] == 'B' and cur[ind - 1] == 'W') {
        swap(cur[ind], cur[space_pos]);
        if (dfs()) {
            solution.push_back(ind);
            return true;
        }
        swap(cur[ind], cur[space_pos]);
    }
 
    return false;
}

int main() {
    ifstream fin("shuttle.in");
    ofstream fout("shuttle.out");

    fin >> n;
    for (int i = 0; i < n; ++i) {
        cur += 'W';
        target += 'B';
    }
    cur += ' ';
    target += ' ';
    for (int i = 0; i < n; ++i) {
        cur += 'B';
        target += 'W';
    }

    dfs();

    int sz = solution.size();
    fout << (solution[sz - 1] + 1);
    for (int i = sz - 2; i >= 0; --i) {
        fout << ((sz - i - 1) % 20 == 0 ? '\n' : ' ') << (solution[i] + 1);
    }
    fout << '\n';
    fout.close();

    return 0;
}
