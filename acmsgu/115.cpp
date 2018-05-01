#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int day, month;
    scanf(" %d %d", &day, &month);
    --day;
    --month;

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month >= 12 or day >= days_in_month[month]) {
        printf("Impossible\n");
        return 0;
    }

    int m = 0;
    int d = 0;
    int dow = 0;
    while (m < month or (m == month and d < day)) {
        ++d;
        if (days_in_month[m] == d) {
            d = 0;
            ++m;
        }

        dow = (dow + 1) % 7;
    }

    printf("%d\n", dow + 1);
    
    return 0;
}
