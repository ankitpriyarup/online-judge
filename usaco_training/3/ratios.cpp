/* ID: rednano1
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>

using namespace std;
int x, y, z, a, b, c, mat[3][3];
int main() {
    ifstream fin  ("ratios.in");    
    ofstream fout ("ratios.out");
    fin >> x >> y >> z;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            fin >> mat[i][j];
        }
    }
    for(int i=0;i<101;i++) {
        for(int j=0;j<101;j++) {
            for(int k=0;k<101;k++) {
                if(i == 0 && j == 0 && k == 0) continue;
                a = i*mat[0][0] + j*mat[1][0] + k*mat[2][0];
                b = i*mat[0][1] + j*mat[1][1] + k*mat[2][1];
                c = i*mat[0][2] + j*mat[1][2] + k*mat[2][2];
                if(a < x || b <y || c < z) continue;
                if(a * y == b * x && a * z == c * x && b *z == c*y) {
                    fout << i << " " << j << " " << k << " " <<(a / x) << endl;
                    return 0;
                }
            }
        }
    }
    fout << "NONE" << endl;
    return 0;
}
