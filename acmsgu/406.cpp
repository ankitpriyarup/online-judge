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

bool in_seq(int v, const vector<int>& seq) {
    for (int x : seq)
        if (x == v)
            return true;

    return false;
}

bool matches(const vector<int>& query, const vector<int>& seq) {
    for (int v : query) {
        if ((v >= 0) ^ in_seq(abs(v), seq))
            return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf(" %d %d", &n, &m);
    vector<vector<int>> seqs(n);
    int k, x;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &k);
        seqs[i].resize(k);
        for (int j = 0; j < k; ++j) {
            scanf(" %d", &seqs[i][j]);
        }
    }

    while (m-- > 0) {
        scanf(" %d", &k);
        vector<int> query(k);
        for (int j = 0; j < k; ++j) {
            scanf(" %d", &query[j]);
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (matches(query, seqs[i])) {
                ans.push_back(i);
            }
        }

        printf("%d\n", (int)ans.size());
        for (int idx : ans) {
            printf("%d", (int)seqs[idx].size());
            for (int x : seqs[idx]) {
                printf(" %d", x);
            }
            printf("\n");
        }
    }

    return 0;
}
