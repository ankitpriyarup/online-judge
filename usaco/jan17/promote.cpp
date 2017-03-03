#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
const int MAXN = 100005;

int n;

// proficiency stuff
int p[MAXN];
pair<int, int> profs[MAXN];

// tree stuff
vector<int> tree[MAXN];
int pre_order[MAXN];
int pre_order_inv[MAXN];
int tree_size[MAXN];
int pre_order_index;

// fenwick tree stuff
int fenwick[MAXN];

int ans[MAXN];

void dfs(int v) {
    tree_size[v] = 1;
    pre_order[pre_order_index] = v;
    pre_order_inv[v] = pre_order_index;

    pre_order_index++;

    for (int child : tree[v]) {
        dfs(child);
        tree_size[v] += tree_size[child];
    }
}

void add(int x) {
    while (x < MAXN) {
        fenwick[x]++;
        x += (x & -x);
    }
}

// return [0, r)
int query(int r) {
    int sum = 0;
    while (r > 0) {
        sum += fenwick[r];
        r -= (r & -r);
    }

    return sum;
}

// return [l, r)
int query(int l, int r) {
    return query(r - 1) - query(l - 1);
}

int main() {
    ifstream fin("promote.in");
    ofstream fout("promote.out");

    fin >> n;

    for (int i = 1; i <= n; ++i) {
        fin >> p[i];
        profs[i - 1] = make_pair(p[i], i);
    }

    sort(profs, profs + n);

    int parent;
    for (int i = 2; i <= n; ++i) {
        fin >> parent;
        tree[parent].push_back(i);
    }

    pre_order_index = 0;
    dfs(1);

    memset(fenwick, 0, sizeof(fenwick));
    for (int i = n - 1; i >= 0; --i) {
        int v = profs[i].second;
        int start = pre_order_inv[v];
        int end = start + tree_size[v];

        ans[v] = query(start + 1, end + 1);
        add(start + 1);
    }

    for (int i = 1; i <= n; ++i) {
        fout << ans[i] << '\n';
    }

    return 0;
}
