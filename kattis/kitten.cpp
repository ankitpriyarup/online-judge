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

int par[1003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    int kitten;
    cin >> kitten;
    getline(cin, s);

    memset(par, -1, sizeof(par));
    int u, v;
    while (true) {
        getline(cin, s);

        istringstream iss(s);
        iss >> u;
        if (u == -1)
            break;

        while (iss >> v) {
            par[v] = u;
        }
    }

    vector<int> stk;
    while (par[kitten] != -1) {
        stk.push_back(kitten);
        kitten = par[kitten];
    }

    stk.push_back(kitten);

    for (int x : stk)
        printf("%d ", x);
    printf("\n");

    return 0;
}
