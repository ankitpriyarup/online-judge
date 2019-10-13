#include <iostream>

using namespace std;

template <typename T>
T ckmin(T& a, T b) {
    return a = min(a, b);
}

template <typename T>
T ckmax(T& a, T b) {
    return a = max(a, b);
}

constexpr int MAXN = 100005;
constexpr int INF = 1e9 + 7;
// SQRT^2 must be > MAXN
constexpr int SQRT = 320;
int n;
int v[MAXN][7];

int lo[2][SQRT][7];
int hi[2][SQRT][7];
int sol[2][SQRT][7];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int p, d;
        cin >> p >> d;
        for (int j = 0; j < 4; ++j) {
            v[i][j] = v[i][6 - j] = p + j * d;
        }
    }

    for (int block = 0; SQRT * block < n; ++block) {
        int start = SQRT * block;
        int end = min(n, SQRT * (block + 1));

        for (int d = 0; d < 7; ++d) {
            lo[0][block][d] = lo[1][block][d] = INF;
            hi[0][block][d] = hi[1][block][d] = -INF;
            for (int i = start, day = d; i < end; ++i, day = (day + 1) % 7) {
                ckmax(sol[0][block][d], v[i][day] - lo[0][block][d]);
                ckmin(lo[0][block][d], v[i][day]);
                ckmax(hi[0][block][d], v[i][day]);
            }

            for (int i = end - 1, day = d; i >= start; --i, day = (day + 1) % 7) {
                ckmax(sol[1][block][d], v[i][day] - lo[1][block][d]);
                ckmin(lo[1][block][d], v[i][day]);
                ckmax(hi[1][block][d], v[i][day]);
            }
        }
    }

    int q;
    cin >> q;
    while (q-- > 0) {
        int s, t;
        cin >> s >> t;
        --s; --t;

        int buy = 1e9 + 7;
        int day = 0;
        int ans = 0;
        if (s < t) {
            for (int i = s; i <= t;) {
                if (i % SQRT == 0 and i + SQRT - 1 <= t) {
                    ckmax(ans, sol[0][i / SQRT][day]);
                    ckmax(ans, hi[0][i / SQRT][day] - buy);
                    ckmin(buy, lo[0][i / SQRT][day]);
                    day = (day + SQRT) % 7;
                    i += SQRT;
                } else {
                    ckmax(ans, v[i][day] - buy);
                    ckmin(buy, v[i][day]);
                    day = (day + 1) % 7;
                    ++i;
                }
            }
        } else {
            for (int i = s; i >= t;) {
                if ((i + 1) % SQRT == 0 and i - SQRT + 1 >= t) {
                    ckmax(ans, sol[1][i / SQRT][day]);
                    ckmax(ans, hi[1][i / SQRT][day] - buy);
                    ckmin(buy, lo[1][i / SQRT][day]);
                    day = (day + SQRT) % 7;
                    i -= SQRT;
                } else {
                    ckmax(ans, v[i][day] - buy);
                    ckmin(buy, v[i][day]);
                    day = (day + 1) % 7;
                    --i;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
