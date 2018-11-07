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
#define sz(X) (int)(X).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

// Based off of https://raw.githubusercontent.com/kth-competitive-programming/kactl/master/content/strings/SuffixArray.h
typedef pair<ll, int> pli;
void count_sort(vector<pli> &b, int bits) { // (optional)
    //this is just 3 times faster than stl sort for N=10^6
    int mask = (1 << bits) - 1;
    rep(it,0,2) {
        int move = it * bits;
        vi q(1 << bits), w(sz(q) + 1);
        rep(i,0,sz(b))
            q[(b[i].first >> move) & mask]++;
        partial_sum(q.begin(), q.end(), w.begin() + 1);
        vector<pli> res(b.size());
        rep(i,0,sz(b))
            res[w[(b[i].first >> move) & mask]++] = b[i];
        swap(b, res);
    }
}
struct SuffixArray {
    vi a;
    string s;
    SuffixArray(const string& _s) : s(_s + '\0') {
        int N = sz(s);
        vector<pli> b(N);
        a.resize(N);
        rep(i,0,N) {
            b[i].first = s[i];
            b[i].second = i;
        }

        int q = 8;
        while ((1 << q) < N) q++;
        for (int moc = 0;; moc++) {
            count_sort(b, q); // sort(all(b)) can be used as well. not for this problem
            a[b[0].second] = 0;
            rep(i,1,N)
                a[b[i].second] = a[b[i - 1].second] +
                    (b[i - 1].first != b[i].first);

            if ((1 << moc) >= N) break;
            rep(i,0,N) {
                b[i].first = (ll)a[i] << q;
                if (i + (1 << moc) < N)
                    b[i].first += a[i + (1 << moc)];
                b[i].second = i;
            }
        }
        rep(i,0,sz(a)) a[i] = b[i].second;
    }

    vi lcp() {
        // longest common prefixes: res[i] = lcp(a[i], a[i-1])
        int n = sz(a), h = 0;
        vi inv(n), res(n);
        rep(i,0,n) inv[a[i]] = i;
        rep(i,0,n) if (inv[i] > 0) {
            int p0 = a[inv[i] - 1];
            while (s[i + h] == s[p0 + h]) h++;
            res[inv[i]] = h;
            if(h > 0) h--;
        }
        return res;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    SuffixArray sa(s);
    vi lcp = sa.lcp();

    int n = sz(sa.a);

    /*
    cout << "SA: ";
    for (int i = 0; i < n; ++i) {
        cout << sa.a[i] << ' ';
    }
    cout << '\n';
    cout << "LCP: ";
    for (int i = 0; i < n; ++i) {
        cout << lcp[i] << ' ';
    }
    cout << '\n';
    */

    int len = 0;
    for (int i = 0; i < n; ++i) {
        if (lcp[i] > len) {
            len = lcp[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (lcp[i] >= len) {
            cout << s.substr(sa.a[i], len);
            return 0;
        }
    }

    return 0;
}
