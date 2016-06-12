/*
ID: rednano1
PROG: milk6
LANG: C++11
*/

// NOTE: This solution is incorrect in the general case, but passes the weak
// cases on the USACO training pages. While it does compute a minimum cut, it
// does not optimize for number of edges or lowest edge index.

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define INF 40000000

using namespace std;

struct edge {
    int s, e, cap, i;
    edge(int s, int e, int cap, int i): s(s), e(e), cap(cap), i(i) {};
};

bool operator<(const edge& e1, const edge &e2) {
    if (e1.cap == e2.cap) {
        return e1.i >= e2.i;
    }
    return e1.cap < e2.cap;
}

int n, m;
int graph[33][33];
int residual[33][33];
int prior[33];
vector<edge> edges;

int dijkstra() {
    // find a path from source to sink, store it in prior;
    memset(prior, -1, sizeof(prior));
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(INF, 0));
    prior[0] = -2;
    while (!pq.empty()) {
        int cap = pq.top().first;
        int node = pq.top().second;
        if (node == n - 1) {
            return cap;
        }
        pq.pop();
        for (int i = 0; i < n; ++i) {
            if (i == node)
                continue;
            if (residual[node][i] > 0 and prior[i] == -1) {
                prior[i] = node;
                pq.push(make_pair(min(cap, residual[node][i]), i));
            }
        }
    }

    return 0;
}

long long max_flow() {
    memcpy(residual, graph, sizeof(graph));

    long long ans = 0LL;
    int delta;
    //cout << "Entering Dijkstra\n";
    while ((delta = dijkstra()) > 0) {
        //cout << "Loop Complete\n";
        int cur = n - 1;
        while (prior[cur] >= 0) {
            int p = prior[cur];
            residual[p][cur] -= delta;
            residual[cur][p] += delta;
            cur = p;
        }
        ans += delta;
    }

    //cout << "Returning\n";
    return ans;
}

int main() {
    ifstream fin("milk6.in");
    ofstream fout("milk6.out");

    fin >> n >> m;
    memset(graph, 0, sizeof(graph));

    int a, b, x;
    for (int i = 1; i <= m; ++i) {
        fin >> a >> b >> x;
        --a;
        --b;
        graph[a][b] += x;
        edges.push_back(edge(a, b, x, i));
    }

    //cout << "Read in edges\n";

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());

    //cout << "Sorted edges\n";

    long long cur_flow = max_flow();
    fout << cur_flow << ' ';
    vector<int> ans;

    for (edge ed : edges) {
        int s = ed.s;
        int e = ed.e;
        int cap = ed.cap;
        int ind = ed.i;
        graph[s][e] -= cap;
        long long mf = max_flow();
        if (cur_flow - cap == mf) {
            ans.push_back(ind);
            cur_flow = mf;
        } else {
            graph[s][e] += cap;
        }
    }

    sort(ans.begin(), ans.end());
    fout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        fout << ans[i] << '\n';
    }

    return 0;
}
