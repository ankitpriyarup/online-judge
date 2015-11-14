/*
ID: rednano1
PROG: kimbits 
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

char out[32];
int N, L;
long long I;

int calc(int len, int b) {
    int sum = 1;
    long long last = 1;
    for (int i = 1; i <= b; ++i) {
        last *= (len + 1 - i);
        last /= i;
        sum += last;
    }

    return sum;
}

void doit(int str_ind, int bitsleft, int set_ind) {
    if (bitsleft == 0 || str_ind >= N) {
        return;
    }

    int zed = calc(N - str_ind - 1, bitsleft);

    if (set_ind >= zed) {
        out[str_ind] = '1';
        doit(str_ind + 1, bitsleft - 1, set_ind - zed);
    } else {
        doit(str_ind + 1, bitsleft, set_ind);
    }
}

int main() {
    ifstream fin ("kimbits.in");    
    ofstream fout("kimbits.out");
    fin >> N >> L >> I;

    I--;
    memset(out, '0', sizeof(out));
    doit(0, L, I);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << i << ", " << j << ": " << calc(i, j) << '\n';
        }
    }

    for (int i = 0; i < N; ++i) {
        fout << out[i];
    }

    fout << endl;
}
