#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <queue>
#include <map>

using namespace std;

using vpii = vector<pair<int, int> >;

const int MAXN = 100005;
int n, w, h;
int a[MAXN];
int id[MAXN];

int g[MAXN], p[MAXN], t[MAXN];

int get_src(const vector<int>& vert, const vector<int>& horiz, const int ind) {
    if (ind < vert.size()) {
        return vert[ind];
    } else {
        return horiz[ind - vert.size()];
    }
}

int get_dest(const vector<int>& vert, const vector<int>& horiz, const int ind) {
    if (ind < horiz.size()) {
        return horiz[ind];
    } else {
        return vert[ind - horiz.size()];
    }
}

int main() {
    scanf("%d %d %d", &n, &w, &h);

    // intersect if horiz_wait + vert_pos = vert_wait + horiz_pos
    // horiz_wait - horiz_pos = vert_wait - vert_pos

    map<int, vector<int> > buckets;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", g + i, p + i, t + i);
        id[i] = i;

        buckets[t[i] - p[i]].push_back(i);
    }

    for (auto entry : buckets) {
        vector<int> vert;
        vector<int> horiz;
        for (auto val : entry.second) {

            if (g[val] == 1) {
                vert.push_back(val);
            } else {
                horiz.push_back(val);
            }
        }

        if (vert.empty() or horiz.empty()) {
            continue;
        }

        sort(begin(vert), end(vert), [](const int& a, const int& b) {
                return p[a] < p[b];
        });
        reverse(begin(vert), end(vert));

        sort(begin(horiz), end(horiz), [](const int& a, const int& b) {
                return p[a] < p[b];
        });

        int vals = vert.size() + horiz.size();
        for (int i = 0; i < vals; ++i) {
            int src = get_src(vert, horiz, i);
            int dest = get_dest(vert, horiz, i);

            id[src] = dest;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (g[id[i]] == 1) {
            printf("%d %d\n", p[id[i]], h);
        } else {
            printf("%d %d\n", w, p[id[i]]);
        }
    }

    return 0;
}
