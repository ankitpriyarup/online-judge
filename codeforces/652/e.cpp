#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 300005;
int n, m;

vi num, st;
vector<pii> ed[MAXN];
int Time;
template<class F>
int dfs(int at, int par, F& f) {
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
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ }
		}
	}

	return top;
}

template<class F>
void bicomps(F f) {
	num.assign(n, 0);
    Time = 0;
    for (int i = 0; i < n; ++i)
        if (!num[i]) dfs(i, -1, f);
}

int u[MAXN], v[MAXN], w[MAXN];

struct DSU {
    int n;
    // uf[x] = parent of x or negative size of component
    vector<int> uf;
    DSU(int n): n(n) {
        uf.assign(n, -1);
    }

    int find(int x) {
        return uf[x] < 0 ? x : (uf[x] = find(uf[x]));
    }

    int merge(int x, int y) {
        int xr = find(x);
        int yr = find(y);
        if (xr == yr)
            return 0;

        if (uf[yr] < uf[xr]) {
            uf[yr] += uf[xr];
            uf[xr] = yr;
        } else {
            uf[xr] += uf[yr];
            uf[yr] = xr;
        }

        return 1;
    }

    vector<vi> get_comps() {
        vector<vi> comps;

        vi comp_id(n, -1);
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            if (comp_id[root] == -1) {
                comp_id[root] = comps.size();
                comps.push_back(vi());
            }

            comps[comp_id[root]].push_back(i);
        }

        return comps;
    }
};

int vis[MAXN];

bool dfs2(DSU& dsu, int uu, int s, int t) {
    vis[uu] = true;
    if (uu == t) {
        dsu.merge(s, t);
        return true;
    }

    bool valid = false;
    for (auto& e : ed[uu]) {
        int vv = e.first;
        if (vis[vv]) continue;

        if (dfs2(dsu, vv, s, t)) {
            valid = true;
        }
    }

    if (valid) {
        dsu.merge(uu, s);
    }

    return valid;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // run bcc algo to get BCCs
    // possible if there's an active edge (u, v)
    // where you can go s -> u -> v -> t
    // obviously possible if all in the same BCC
    // add an edge back from t to s. Then its possible iff 
    // all in same bcc

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        --u[i]; --v[i];
        ed[u[i]].emplace_back(v[i], i);
        ed[v[i]].emplace_back(u[i], i);
    }

    int s, t;
    cin >> s >> t;
    --s; --t;
    DSU dsu(n);
    bicomps([&](const vi& edges) {
        // cout << "COMP\n";
        for (int eid : edges) {
            dsu.merge(u[eid], v[eid]);
        }
    });

    dfs2(dsu, s, s, t);
    bool valid = false;
    for (int i = 0; i < m; ++i) {
        if (w[i] and dsu.find(u[i]) == dsu.find(s) and dsu.find(v[i]) == dsu.find(s)) {
            valid = true;
            break;
        }
    }

    cout << (valid ? "YES" : "NO") << '\n';

    return 0;
}
