#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>

#define MAX_N 50005
using namespace std;

int N;
int high[MAX_N / 2 + 5];
int low[MAX_N / 2 + 5];
int elsie[MAX_N];
int elsie2[MAX_N];

int main() {
    ifstream fin("cardgame.in");
    ofstream fout("cardgame.out");

    fin >> N;

    for (int i = 0; i < N; ++i) {
        fin >> elsie[i];
        elsie2[i] = elsie[i];
    }
    sort(elsie2, elsie2 + N);

    int epos = 0;
    int lowpos = 0;
    int hipos = 0;

    for (int i = 1; i <= 2 * N; ++i) {
        if (i == elsie2[epos]) {
            epos++;
        } else {
            if (lowpos < N / 2) {
                low[lowpos] = i;
                lowpos++;
            } else {
                high[hipos] = i;
                hipos++;
            }
        }
    }

    int ans = 0;

    // play the high game
    sort(elsie, elsie + N / 2);
    int j = N / 2 - 1;
    for (int i = N / 2 - 1; i >= 0; --i) {
        //cout << elsie[i] << " " << high[j] << '\n';
        if (elsie[i] < high[j]) {
            ans++;
            j--;
        }
    }

    j = 0;
    sort(elsie + N / 2, elsie + N);
    for (int i = N / 2; i < N; ++i) {
        //cout << elsie[i] << " " << low[j] << '\n';
        if (elsie[i] > low[j]) {
            ans++;
            j++;
        }
    }

    fout << ans << '\n';
    return 0;
}
