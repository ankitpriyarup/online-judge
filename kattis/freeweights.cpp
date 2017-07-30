#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1000006;
int n;
int weights[2][MAXN];
vector<int> v;

bool works(int moved) {
    for (int i = 0; i < 2; ++i) {
        v.clear();
        for (int j = 0; j < n; ++j) {
            if (weights[i][j] > moved) {
                v.push_back(weights[i][j]);
            }
        }

        if (v.size() % 2 == 1) {
            return false;
        }

        for (int j = 0; j < v.size(); j += 2) {
            if (v[j] != v[j + 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &weights[i][j]);
        }
    }

    // dont move any weights
    if (works(0)) {
        printf("%d\n", 0);
        return 0;
    }

    int lo = 0;
    int hi = 1e9 + 7;

    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (works(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%d\n", hi);

    return 0;
}
