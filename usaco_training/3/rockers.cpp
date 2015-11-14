/*
ID: rednano1
PROG: rockers
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int N, M, T;
int songs[22];
int main() {
    ifstream fin ("rockers.in");
    ofstream fout("rockers.out");

    fin >> N >> T >> M;
    for (int i = 0; i < N; ++i) {
        fin >> songs[i];
    }

    fin.close();

    int ans = 0;
    for (int i = 0; i < (1 << N); ++i) {
        int count = 0;
        int cd = 0;
        int filled = 0;

        for (int j = 0; j < N; ++j) {
            if ((1 << j) & i) {
                if (songs[j] > T) {
                    count = -1;
                    break;
                }

                if (filled + songs[j] > T) {
                    cd++;
                    if (cd == M) {
                        break;
                    }

                    filled = songs[j];
                } else {
                    filled += songs[j];
                }

                count++;
            }
        }

        ans = max(ans, count);
        //cout << i << ' ' << count << '\n';
    }

    fout << ans << '\n';
    fout.close();
    return 0;
}
