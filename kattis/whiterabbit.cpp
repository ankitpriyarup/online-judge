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

constexpr int MAXN = 202;
constexpr int MOD = 13;
constexpr int inv[] = {0, 1, 7, 9, 10, 8, 11, 2, 5, 3, 4, 6, 12};
int n, num_trips, src, dest;

void print_matrix(const vector<vector<int>>& mat) {
    return;
    int r = mat.size();
    int c = mat[0].size();
    printf("Matrix!\n");
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
}

void reduce(vector<vector<int>>& mat) {
    int r = mat.size();
    int c = mat[0].size();
    for (int i = 0; i < c - 1; ++i) {
        int pivot = i;
        while (pivot < r and mat[pivot][i] == 0)
            ++pivot;

        if (pivot == r) continue;
        for (int j = 0; j < c; ++j)
            swap(mat[i][j], mat[pivot][j]);

        int coeff = inv[mat[i][i]];
        for (int j = 0; j < c; ++j) {
            mat[i][j] *= coeff;
            mat[i][j] %= MOD;
        }

        for (int k = i + 1; k < r; ++k) {
            if (mat[k][i] == 0) continue;
            int coeff = 13 - mat[k][i];
            for (int j = 0; j < c; ++j) {
                mat[k][j] = (mat[k][j] + coeff * mat[i][j]) % MOD;
            }
        }

        print_matrix(mat);
    }

    for (int i = c - 2; i >= 0; --i) {
        if (mat[i][i] == 0) continue;
        for (int k = i - 1; k >= 0; --k) {
            if (mat[k][i] == 0) continue;
            int coeff = 13 - mat[k][i];
            for (int j = 0; j < c; ++j) {
                mat[k][j] = (mat[k][j] + coeff * mat[i][j]) % MOD;
            }
        }

        print_matrix(mat);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d %d %d", &n, &src, &dest, &num_trips);
    vector<vector<int> > trips(num_trips);
    vector<int> times(num_trips);
    vector<pii> edges;
    for (int i = 0; i < num_trips; ++i) {
        int k;
        scanf("%d", &times[i]);
        scanf("%d", &k);
        trips[i].resize(k);

        for (int j = 0; j < k; ++j) {
            scanf("%d", &trips[i][j]);
            if (j) {
                int u = trips[i][j];
                int v = trips[i][j - 1];
                if (u > v) swap(u, v);
                assert(u != v);
                edges.emplace_back(u, v);
            }
        }
    }

    sort(begin(edges), end(edges));
    edges.resize(unique(begin(edges), end(edges)) - begin(edges));

    int num_edges = edges.size();
    vector<vector<int>> mat(num_trips, vector<int>(num_edges + 1, 0));

    /*
    printf("%d edges\n", num_edges);
    for (int i = 0; i < num_edges; ++i) {
        printf("Edge %d: (%d, %d)\n", i, edges[i].first, edges[i].second);
    }
    */

    for (int i = 0; i < num_trips; ++i) {
        for (int j = 1; j < trips[i].size(); ++j) {
            int u = trips[i][j];
            int v = trips[i][j - 1];
            if (u > v) swap(u, v);

            int idx = lower_bound(begin(edges), end(edges), make_pair(u, v)) - begin(edges);
            ++mat[i][idx];
            mat[i][idx] %= MOD;
        }

        mat[i][num_edges] = times[i];
    }

    print_matrix(mat);
    reduce(mat);
    // print_matrix(mat);

    vector<vector<pii> > graph(n + 1);
    for (int i = 0; i < min(num_edges, num_trips); ++i) {
        if (mat[i][i] != 1) continue;
        graph[edges[i].first].emplace_back(edges[i].second, mat[i].back());
        graph[edges[i].second].emplace_back(edges[i].first, mat[i].back());
    }

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    constexpr int INF = 1e9;
    vector<int> dist(n + 1, INF);
    dist[src] = 0;
    pq.emplace(0, src);

    int cur_dist, u;
    while (!pq.empty()) {
        tie(cur_dist, u) = pq.top();
        pq.pop();
        if (cur_dist != dist[u]) continue;
        for (auto& e : graph[u]) {
            int v = e.first;
            int new_dist = cur_dist + e.second;
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.emplace(new_dist, v);
            }
        }
    }

    printf("%d\n", dist[dest]);

    return 0;
}
