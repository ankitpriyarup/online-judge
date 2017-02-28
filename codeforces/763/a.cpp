#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

const int MAXN = 100005;
int n;
int c[MAXN];

vector<pair<int, int> > edges, suspect;

int main() {
    ios_base::sync_with_stdio(false);

    scanf("%d", &n);

    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d %d", &u, &v);
        edges.push_back({u, v});
    }

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }

    for (pair<int, int> edge : edges) {
        if (c[edge.first] != c[edge.second]) {
            suspect.push_back(edge);
        }
    }

    if (suspect.size() == 0) {
        printf("YES\n1\n");
    } else {
        int s1 = suspect[0].first;
        int s2 = suspect[0].second;

        bool b1 = true;
        bool b2 = true;

        for (int i = 1; i < suspect.size(); ++i) {
            if (s1 != suspect[i].first and s1 != suspect[i].second) {
                b1 = false;
            }
            if (s2 != suspect[i].first and s2 != suspect[i].second) {
                b2 = false;
            }
        }

        if (b1) {
            printf("YES\n%d\n", s1);
        } else if (b2) {
            printf("YES\n%d\n", s2);
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
