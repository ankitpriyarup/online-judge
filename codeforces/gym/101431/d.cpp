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

int n, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &x);
    vector<vector<int> > res(n, vector<int>(x));
    vector<int> row(n * x + 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < x; ++j) {
            res[i][j] = x * i + j + 1;
            row[x * i + j + 1] = i;
        }
    }

    vector<vector<int> > snd(n, vector<int>(x));

    vector<int> ptrs(n, 0);
    int sp = 1;
    bool poss = true;
    for (int i = 0; poss and i < n; ++i) {
        int p = sp;
        for (int j = 0; poss and j < x; ++j) {
            if (ptrs[p] >= x or row[res[p][ptrs[p]]] == i) {
                poss = false;
                break;
            }

            snd[i][j] = res[p][ptrs[p]];
            ++ptrs[p];
            p = (p + 1) % n;
        }

        sp = (sp + 1) % n;
    }

    if (!poss) {
        printf("%d\n", -1);
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < x; ++j) {
            printf("%d ", res[i][j]);
        }
        for (int j = 0; j < x; ++j) {
            printf("%d ", snd[i][j]);
        }
        printf("\n");
    }

    return 0;
}
