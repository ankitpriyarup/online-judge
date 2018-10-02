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

    int x, y;
    scanf(" %d %d", &x, &y);

    bool is_ciel = true;
    while (true) {
        if (is_ciel) {
            bool poss = false;
            for (int xt = 2; xt >= 0; --xt) {
                int yt = (220 - 100 * xt) / 10;
                if (xt <= x and yt <= y) {
                    // printf("Take %d %d\n", xt, yt);
                    x -= xt;
                    y -= yt;
                    poss = true;
                    break;
                }
            }

            if (!poss)
                break;
        } else {
            bool poss = false;
            for (int yt = 22; yt >= 0; yt -= 10) {
                int xt = (220 - 10 * yt) / 100;
                if (xt <= x and yt <= y) {
                    // printf("Take %d %d\n", xt, yt);
                    x -= xt;
                    y -= yt;
                    poss = true;
                    break;
                }
            }

            if (!poss)
                break;
        }

        is_ciel = !is_ciel;
    }

    printf("%s\n", is_ciel ? "Hanako" : "Ciel");
    
    return 0;
}
