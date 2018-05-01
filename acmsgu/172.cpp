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

// KACTL KACTL
struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int add_var() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = (f >= 0 ? 2*f : -1-2*f);
		j = (j >= 0 ? 2*j : -1-2*j);
		gr[f^1].push_back(j);
		gr[j^1].push_back(f);
	}

	void set_value(int x) { either(x, x); }

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for (auto& e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = !(x&1);
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		for (int i = 0; i < 2 * N; ++i) if (!comp[i]) dfs(i);
		for (int i = 0; i < N; ++i) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    scanf(" %d %d", &n, &m);
    TwoSat ts(n);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf(" %d %d", &u, &v);
        --u; --v;
        ts.either(u, v);
        ts.either(~u, ~v);
    }

    if (ts.solve()) {
        printf("yes\n");
        int total = 0;
        for (int i = 0; i < n; ++i)
            total += ts.values[i];

        printf("%d\n", total);
        for (int i = 0; i < n; ++i)
            if (ts.values[i])
                printf("%d ", i + 1);
        printf("\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
