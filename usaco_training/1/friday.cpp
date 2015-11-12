/*
ID: rednano1
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int ans[7];
int days[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int N, md;

int feb_days(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 29;
    } else {
        return 28;
    }
}

int main(){
    ifstream fin  ("friday.in");
    ofstream fout ("friday.out");

    fin >> N;
    int day = 0; //first 1/13/1900 was a saturday

    for (int year = 1900; year < 1900 + N; ++year) {
        for (int month = 0; month < 12; ++month) {
            ans[day]++;
            md = days[month] == -1 ? feb_days(year) : days[month];
            day += md;
            day %= 7;
        }
    }

    for (int i = 0; i < 6; ++i) {
      fout << ans[i] << ' ';
    }
    fout << ans[6] << '\n';

    return 0;
}
