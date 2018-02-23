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

int x[5005], y[5005];
bool clash(int i, int j) {
    return x[i] == x[j] or y[i] == y[j] or x[i] + y[i] == x[j] + y[j] or x[i] - y[i] == x[j] - y[j];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    bool good = true;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", x + i, y + i);
        if (good) {
            for (int j = 0; j < i; ++j) {
                if (clash(i, j)) {
                    good = false;
                }
            }
        }
    }

    printf("%s\n", good ? "CORRECT" : "INCORRECT");
    
    return 0;
}
