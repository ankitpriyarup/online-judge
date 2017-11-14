#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int SIZE = 23;
char board[SIZE + 3];

bool visit[1 << SIZE];

inline bool has_bit(int bs, int i) {
    return (bs & (1 << i)) > 0;
}

inline int set_bit(int& bs, int i, int val) {
    if (val)
        return bs | (1 << i);
    else
        return bs ^ (1 << i);
}

void print_state(int x) {
    /*
    for (int i = 0; i < SIZE; ++i) {
        printf("%c", (x & (1 << i)) ? 'o' : '-');
    }
    printf("\n");
    */
}

void solve() {
    memset(visit, 0, sizeof(visit));
    int state = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (board[i] == 'o') {
            state |= (1 << i);
        }
    }

    queue<int> q;
    q.push(state);
    visit[state] = true;

    int ans = __builtin_popcount(state);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        print_state(cur);
        ans = min(ans, __builtin_popcount(cur));

        // try jumping forward
        for (int i = 0; i + 2 < SIZE; ++i) {
            if (has_bit(cur, i) and has_bit(cur, i + 1) and !has_bit(cur, i + 2)) {

                int next_state = set_bit(cur, i, 0);
                next_state = set_bit(next_state, i + 1, 0);
                next_state = set_bit(next_state, i + 2, 1);

                if (!visit[next_state]) {
                    visit[next_state] = true;
                    q.push(next_state);
                }
            }
        }

        // and backwards
        for (int i = 2; i < SIZE; ++i) {
            if (!has_bit(cur, i - 2) and has_bit(cur, i - 1) and has_bit(cur, i)) {

                int next_state = set_bit(cur, i - 2, 1);
                next_state = set_bit(next_state, i - 1, 0);
                next_state = set_bit(next_state, i, 0);

                if (!visit[next_state]) {
                    visit[next_state] = true;
                    q.push(next_state);
                }
            }
        }
    }

    printf("%d\n", ans);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        scanf("%s", board);
        memset(visit, false, sizeof(visit));
        solve();
    }

    return 0;
}
