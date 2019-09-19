#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    
    SuffixArray sa(s);
    int lo = 0;
    int hi = n;

    /*
    cout << "SA:";
    for (int i = 0; i <= n; ++i) {
        cout << " " << sa.sa[i];
    }
    cout << '\n';

    cout << "LCP:";
    for (int i = 0; i <= n; ++i) {
        cout << " " << sa.lcp[i];
    }
    cout << '\n';
    */

    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;

        bool found = false;
        for (int i = 1; i <= n; ++i) {
            int first = sa.sa[i];
            int last = sa.sa[i];
            int j = i;
            while (j + 1 <= n and sa.lcp[j + 1] >= mid) {
                ++j;
                first = min(first, sa.sa[j]);
                last = max(last, sa.sa[j]);
            }

            i = j;

            if (first + mid <= last) {
                found = true;
                break;
            }
        }

        if (found) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';
    
    return 0;
}
