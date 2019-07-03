#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 300005;
int n;
int p[MAXN], loc[MAXN];

void do_swap(vector<pii>& moves, int i, int j) {
    int pi = p[i];
    int pj = p[j];
    moves.emplace_back(i, j);
    p[i] = pj;
    p[j] = pi;
    loc[pi] = j;
    loc[pj] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        loc[p[i]] = i;
    }

    int h = n >> 1;
    vector<pii> moves;
    for (int v = 0; v < n; ++v) {
        if (loc[v] == v) continue;

        int i = loc[v];
        int j = v;
        if (abs(i - j) >= h) {
            do_swap(moves, i, j);
        } else if (i < h and j < h) {
            do_swap(moves, i, n - 1);
            do_swap(moves, j, n - 1);
            do_swap(moves, i, n - 1);
        } else if (i >= h and j >= h) {
            do_swap(moves, i, 0);
            do_swap(moves, j, 0);
            do_swap(moves, i, 0);
        } else if (i >= h and j < h) {
            do_swap(moves, i, 0);
            do_swap(moves, j, n - 1);
            do_swap(moves, 0, n - 1);
            do_swap(moves, i, 0);
            do_swap(moves, j, n - 1);
        } else if (i < h and j >= h) {
            do_swap(moves, i, n - 1);
            do_swap(moves, j, 0);
            do_swap(moves, 0, n - 1);
            do_swap(moves, i, n - 1);
            do_swap(moves, j, 0);
        }
    }

    cout << moves.size() << '\n';
    for (auto& m : moves) {
        int x, y;
        tie(x, y) = m;
        cout << (x + 1) << ' ' << (y + 1) << '\n';
    }
    
    return 0;
}
