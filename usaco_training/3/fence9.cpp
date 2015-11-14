/*
ID: rednano1
PROG: fence9
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int N, M, P;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int bounds(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        return abs(y2 - y1) + 1;
    } else if (y1 == y2) {
        return abs(x2 - x1) + 1;
    } else {
        int xd = abs(x2 - x1);
        int yd = abs(y2 - y1);

        int g = gcd(xd, yd);

        int denom = xd / g;

        return xd / denom + 1;
    }
}

int main() {
    ifstream fin ("fence9.in");
    ofstream fout("fence9.out");

    fin >> N >> M >> P;

    // Pick's theorem
    // 2 A - 2i + 2 = b
    long long area = 1LL * P * M;

    // count the number of boundary points
    long long boundary_points = 0;

    boundary_points += bounds(0, 0, N, M);
    boundary_points += bounds(N, M, P, 0);
    boundary_points += bounds(P, 0, 0, 0);
    boundary_points -= 3;

    fout << ((area - boundary_points + 2) / 2) << '\n';
    return 0;
}
