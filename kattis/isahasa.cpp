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

constexpr int MAXN = 505;
int n;
vector<string> words;
bool is[MAXN][MAXN];
bool has[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> n >> q;
    string a, b, rel;

    vector<pair<string, string> > is_p, has_p;
    for (int i = 0; i < n; ++i) {
        cin >> a >> rel >> b;
        words.push_back(a);
        words.push_back(b);
        if (rel == "is-a") {
            is_p.push_back({a, b});
        } else {
            has_p.push_back({a, b});
        }
    }

    sort(begin(words), end(words));
    words.resize(unique(begin(words), end(words)) - begin(words));

    memset(is, 0, sizeof(is));
    memset(has, 0, sizeof(has));

    n = words.size();
    for (int i = 0; i < n; ++i) {
        is[i][i] = true;
    }

    for (pair<string, string>& p : is_p) {
        int x = lower_bound(begin(words), end(words), p.first) - begin(words);
        int y = lower_bound(begin(words), end(words), p.second) - begin(words);

        is[x][y] = true;
    }

    for (pair<string, string>& p : has_p) {
        int x = lower_bound(begin(words), end(words), p.first) - begin(words);
        int y = lower_bound(begin(words), end(words), p.second) - begin(words);

        has[x][y] = true;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                is[i][j] = is[i][j] or (is[i][k] and is[k][j]);
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                has[i][j] = has[i][j] or (has[i][k] and has[k][j]);
                has[i][j] = has[i][j] or (has[i][k] and is[k][j]);
                has[i][j] = has[i][j] or (is[i][k] and has[k][j]);
            }
        }
    }

    int tc = 1;
    while (q-- > 0) {
        printf("Query %d: ", tc++);
        cin >> a >> rel >> b;
        int x = lower_bound(begin(words), end(words), a) - begin(words);
        int y = lower_bound(begin(words), end(words), b) - begin(words);

        bool res = false;
        if (rel == "is-a") {
            res = is[x][y];
        } else {
            res = has[x][y];
        }

        if (res) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }

    return 0;
}
