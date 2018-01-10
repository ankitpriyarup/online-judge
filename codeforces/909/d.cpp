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

constexpr int MAXN = 1000006;
constexpr int INF = 1e9;
int n;
char s[MAXN];

int dumb() {
    vector<char> v(s, s + n);
    int ans = 0;

    while (v.size() > 0) {
        /*
        printf("%d ", v.size());
        for (char c : v)
            printf("%c", c);
        printf("\n");
        */

        bool purged = false;
        vector<bool> purge(v.size(), false);
        for (int i = 0; i < v.size(); ++i) {
            for (int d = -1; d <= 1; d += 2) {
                if (0 <= i + d and i + d < v.size()) {
                    purge[i] = (purge[i] or v[i] != v[i + d]);
                    if (purge[i]) {
                        // printf("Purging %d based on %d\n", i, i + d);
                        purged = true;
                    }
                }
            }
        }

        if (!purged) {
            break;
        }

        vector<char> v2;
        for (int i = 0; i < v.size(); ++i) {
            if (!purge[i])
                v2.push_back(v[i]);
        }

        v = v2;

        ++ans;
    }

    return ans;
}

int smart() {
    vector<pair<char, int> > rle;
    for (int i = 0; i < n; ++i) {
        if (!rle.empty() and rle.back().first == s[i])
            ++rle.back().second;
        else
            rle.push_back({s[i], 1});
    }

    int ans = 0;
    while (rle.size() > 1) {
        vector<pair<char, int> > nxt;
        for (int i = 0; i < rle.size(); ++i) {
            // printf("%c %d\n", rle[i].first, rle[i].second);
            int d = rle[i].second;
            if (i == 0 or i == rle.size() - 1) {
                --d;
            } else {
                d -= 2;
            }

            if (d > 0) {
                if (!nxt.empty() and nxt.back().first == rle[i].first)
                    nxt.back().second += d;
                else
                    nxt.push_back({rle[i].first, d});
            }
        }

        rle = nxt;
        ++ans;
        /*
        printf("--\n");
        for (int i = 0; i < rle.size(); ++i) {
            printf("%c %d\n", rle[i].first, rle[i].second);
        }
        printf("-----\n");
        */
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%s", s);
    n = strlen(s);

    int a = smart();
    /*
    int b = dumb();
    if (a != b) {
        printf("SMART: %d\n", a);
        printf(" DUMB: %d\n", b);
    }
    assert(a == b);
    */
    printf("%d\n", a);

    return 0;
}
