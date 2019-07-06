#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr ll INF = 1e18;

// from benq
template<class T, int SZ>
struct LazySegTree {
    T sum[2*SZ], mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2

    LazySegTree() {
        memset (sum,0,sizeof sum);
        memset (mn,0,sizeof mn);
        memset (lazy,0,sizeof lazy);
    }

    void push(int ind, int L, int R) {
        sum[ind] += (R-L+1)*lazy[ind];
        mn[ind] += lazy[ind];
        if (L != R) lazy[2*ind] += lazy[ind], lazy[2*ind+1] += lazy[ind];
        lazy[ind] = 0;
    }

    void pull(int ind) {
        sum[ind] = sum[2*ind]+sum[2*ind+1];
        mn[ind] = min(mn[2*ind],mn[2*ind+1]);
    }

    T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return sum[ind];

        int M = (L+R)/2;
        return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
    }

    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];

        int M = (L+R)/2;
        return min(qmin(lo,hi,2*ind,L,M), qmin(lo,hi,2*ind+1,M+1,R));
    }

    void upd(int lo, int hi, ll inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }

        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};

class DejaVu {
public:
    int solve(vector<ll> M) {
        // keep track of interval when each value is active
        // between the second and third most recent ones
        // keep a lazy seg tree
        // add on interval
        // sub on interval
        // find max over whole range
        map<int, deque<int>> by_val;
        int n = M.size();
        int ans = 0;
        LazySegTree<int, (1<<18)> lst;
        for (int i = 0; i < n; ++i) {
            int x = M[i];
            if (by_val[x].empty()) {
                by_val[x].push_back(-1);
            }
            by_val[x].push_back(i);
            if (by_val[x].size() == 3) {
                int a = by_val[x][0];
                int b = by_val[x][1];
                lst.upd(a + 1, b, -1);
            } else if (by_val[x].size() == 4) {
                int a = by_val[x][0];
                int b = by_val[x][1];
                int c = by_val[x][2];
                lst.upd(a + 1, b, 1);
                lst.upd(b + 1, c, -1);
                by_val[x].pop_front();
            }

            ans = max(ans, -lst.qmin(0, n));
        }

        return ans;
    }

    int mostDejaVus(int N, int seed, int R) {
        vector<ll> A(N), M(N);
        A[0] = seed;
        M[0] = A[0] % R;
        for (int i = 1; i < N; ++i) {
            A[i] = (A[i - 1] * 1664525LL + 1013904223LL) % 4294967296LL;
            M[i] = A[i] % R;
        }

        return solve(M);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    DejaVu dv;

    return 0;
}
