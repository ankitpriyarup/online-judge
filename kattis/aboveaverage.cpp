#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

    int T;
    scanf("%d", &T);
    int n;
    while (T-- > 0) {
        scanf("%d", &n);
        vector<int> v;
        int x;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            v.push_back(x);
            sum += x;
        }

        int above = 0;
        for (int i = 0; i < n; ++i) {
            // avg is sum / n
            // above average if grade > sum / n => n * grade > sum
            if (n * v[i] > sum) {
                ++above;
            }
        }

        printf("%.3lf%%\n", (100.0 * above) / (n));
    }
    
    return 0;
}
