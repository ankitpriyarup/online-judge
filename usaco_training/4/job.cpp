/*
ID: rednano1
PROG: job
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <functional>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M1, M2;
int a[33], b[33];

int main() {
    ifstream fin("job.in");
    ofstream fout("job.out");

    fin >> N >> M1 >> M2;
    for (int i = 0; i < M1; ++i) {
        fin >> a[i];
    }
    for (int i = 0; i < M2; ++i) {
        fin >> b[i];
    }

    sort(a, a + M1);
    sort(b, b + M2);

    fout << asol << '\n';
    return 0;
}
