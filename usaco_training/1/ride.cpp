/*
ID: rednano1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    int p1 = 1, p2 = 1;
    ifstream fin  ("ride.in");
    ofstream fout ("ride.out");
    
    fin >> s1 >> s2;
    
    for(int i = 0; i < s1.length(); i++) {
        p1 *= s1[i] - 'A' + 1;
    }
    for(int i = 0; i < s2.length(); i++) {
        p2 *= s2[i] - 'A' + 1;
    }

    if(p1 % 47 == p2 % 47) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }

    return 0;
}
