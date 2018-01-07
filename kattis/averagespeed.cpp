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

char s[10000];

int parse(char* s) {
    return 10 * (s[0] - '0') + (s[1] - '0');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int last = 0;
    int speed = 0;
    ll dist = 0LL;

    while (gets(s)) {
        int hh = parse(s + 0);
        int mm = parse(s + 3);
        int ss = parse(s + 6);
        int time = ss + 60 * (mm + 60 * hh);
        dist += (time - last) * speed;

        if (s[8] == ' ') {
            speed = atoi(s + 9);
        } else {
            printf("%s %.2lf km\n", s, dist / 60.0 / 60.0);
        }

        last = time;
    }

    return 0;
}
