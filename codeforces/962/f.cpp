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
using vi = vector<int>;

int n, m;
vector<vector<pii> > ed;
int Time;
vi num, st;
// KACTL
template<class F>
int dfs(int at, int par, F f) {
	int me = num[at] = ++Time, e, y, top = me;
	for (auto& pa : ed[at]) if (pa.second != par) {
		tie(y, e) = pa;
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = st.size();
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
				f(vi(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me)
				st.push_back(e);
			// else e is a bridge
		}
	}
	return top;
}

template<class F>
void bicomps(F f) {
	num.assign(ed.size(), 0);
	for(int i = 0; i < n; ++i) if (!num[i]) dfs(i, -1, f);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &m);
    ed.resize(n);
    vector<pii> edges(m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        --u; --v;
        ed[u].emplace_back(v, i);
        ed[v].emplace_back(u, i);
        edges[i] = {u, v};
    }

    vi valid;
    bicomps([&](const vi& edgelist) {
        vi verts;
        for (int x : edgelist) {
            verts.push_back(edges[x].first);
            verts.push_back(edges[x].second);
        }

        sort(begin(verts), end(verts));
        verts.resize(unique(begin(verts), end(verts)) - begin(verts));
        int num_verts = verts.size();
        int num_edges = edgelist.size();
        if (num_verts == num_edges) {
            for (int x : edgelist)
                valid.push_back(x);
        }
    });

    sort(begin(valid), end(valid));
    printf("%lu\n", valid.size());
    for (int x : valid)
        printf("%d ", x + 1);
   
    return 0;
}
