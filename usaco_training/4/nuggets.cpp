/*
ID: rednano1
PROG: nuggets
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N;
int nuggets[11];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ifstream fin ("nuggets.in");
    ofstream fout("nuggets.out");
    fin >> N;

    for (int i = 0; i < N; ++i) {
        fin >> nuggets[i];
    }
    fin.close();

    sort(nuggets, nuggets + N);

    int mem_size = nuggets[0];
    int g = nuggets[0];
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(nuggets[0]);

    for (int i = 1; i < N; ++i) {
        g = gcd(g, nuggets[i]);
        pq.push(nuggets[i]);
    }

    if (nuggets[0] == 1 || g > 1) {
        fout << "0\n"; 
        return 0;
    }

    int last = -1;
    int chain = 0;
    while (!pq.empty()) {
        int c = pq.top();
        pq.pop();

        if (c == last) {
            continue;
        }

        if (c == last + 1) {
            chain++;
        } else {
            chain = 1;
        }

        last = c;
        if (chain == mem_size) {
            break;
        }

        for (int i = 0; i < N; ++i) {
            pq.push(c + nuggets[i]);
        }
    }

    fout << (last - chain) << '\n';
    return 0;
}
