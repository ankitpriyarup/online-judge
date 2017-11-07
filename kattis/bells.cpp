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

constexpr int MAXP = 50000;
constexpr int MAXN = 10;
int n;

vector<vector<int> > upgrade(const vector<vector<int> >& src, int val) {
    vector<vector<int> > ret;
    for (int i = 0; i < src.size(); i += 2) {
        // forward
        vector<int> base(begin(src[i]), end(src[i]));
        for (int j = 0; j < val; ++j) {
            vector<int> copy(begin(base), end(base));
            copy.insert(copy.begin() + j, val);
            ret.push_back(copy);
        }

        // backwards
        vector<int> base2(begin(src[i + 1]), end(src[i + 1]));
        for (int j = 0; j < val; ++j) {
            vector<int> copy(begin(base2), end(base2));
            copy.insert(copy.begin() + (val - j - 1), val);
            ret.push_back(copy);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    if (n == 1) {
        printf("%d\n", 1);
        return 0;
    }

    vector<vector<int> > ans = {{1, 2}, {2, 1}};
    for (int i = 3; i <= n; ++i) {
        ans = upgrade(ans, i);
    }

    int offset = 0;
    for (int i = 0; i < ans.size(); i++) {
        bool ident = true;
        for (int j = 0; j < n; ++j)
            if (ans[i][j] != j + 1)
                ident = false;

        offset = i;
        if (ident)
            break;
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int x : ans[(i + offset) % ans.size()]) {
            printf("%d ", x);
        }
        printf("\n");
    }

    return 0;
}
