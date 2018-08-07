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

void preorder(vector<int>& pre, const vector<pii>& tree, int node) {
    if (node == 0) {
        return;
    }

    pre.push_back(node);
    preorder(pre, tree, tree[node].first);
    preorder(pre, tree, tree[node].second);
}

void postorder(vector<int>& post, const vector<pii>& tree, int node) {
    if (node == 0) {
        return;
    }

    postorder(post, tree, tree[node].first);
    postorder(post, tree, tree[node].second);
    post.push_back(node);
}

int find(vector<int>& uf, int x) {
    return uf[x] = (x == uf[x] ? x : find(uf, uf[x]));
}

int merge(vector<int>& uf, int x, int y) {
    int xr = find(uf, x);
    int yr = find(uf, y);
    if (xr == yr) {
        return false;
    }

    uf[xr] = yr;
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pii> children(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> children[i].first >> children[i].second;
    }

    vector<int> pre, post;
    preorder(pre, children, 1);
    postorder(post, children, 1);

    vector<int> uf(n + 1);
    iota(begin(uf), end(uf), 0);

    assert(pre.size() == n);
    assert(pre.size() == post.size());
    for (int i = 0; i < n; ++i) {
        merge(uf, pre[i], post[i]);
    }

    vector<int> ans(n + 1, 0);
    vector<int> rep_to_label(n + 1, -1);
    int next_label = 0;
    for (int i = 1; i <= n; ++i) {
        int rep = find(uf, i);
        if (rep_to_label[rep] == -1) {
            rep_to_label[rep] = next_label++;
        }

        ans[i] = (rep_to_label[rep] % k) + 1;
    }

    if (next_label < k) {
        cout << "Impossible\n";
    } else {
        for (int i = 0; i < n; ++i) {
            assert(ans[pre[i]] == ans[post[i]]);
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " \n"[i == n];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }

    return 0;
}
