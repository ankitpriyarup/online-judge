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

int n, a, b;
char s[222];
vector<int> inds[3];
int changes = 0;

void transfer(int x, int y) {
    s[inds[x].back()] = '0' + y;
    inds[y].push_back(inds[x].back());
    inds[x].pop_back();
    ++changes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf(" %d %d %d", &n, &a, &b);
    scanf(" %s", s);
    for (int i = 0; i < n; ++i) {
        inds[s[i] - '0'].push_back(i);
    }

    if (a + b > n) {
        printf("-1\n");
        return 0;
    }

    while (inds[0].size() > a and inds[1].size() < b) {
        transfer(0, 1);
    }

    while (inds[1].size() > b and inds[0].size() < a) {
        transfer(1, 0);
    }

    while (inds[0].size() > a) {
        transfer(0, 2);
    }

    while (inds[1].size() > b) {
        transfer(1, 2);
    }

    while (inds[0].size() < a) {
        transfer(2, 0);
    }

    while (inds[1].size() < b) {
        transfer(2, 1);
    }

    printf("%d\n", changes);
    printf("%s\n", s);
    return 0;
}
