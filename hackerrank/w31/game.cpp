#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100005;
int n;
int a[MAXN], forw[MAXN], back[MAXN];

void read() {
    memset(a, -1, sizeof(a));
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        back[i] = i - 1;
        forw[i] = i + 1;
    }

    forw[n - 1] = -1;
}

bool is_free(int ptr) {
    return forw[ptr] != -1 
       and back[ptr] != -1 
       and a[forw[ptr]] == 0 
       and a[back[ptr]] == 0;
}

void remove(int ptr) {
    if (forw[ptr] != -1) {
        back[forw[ptr]] = back[ptr];
    }

    if (back[ptr] != -1) {
        forw[back[ptr]] = forw[ptr];
    }

    a[ptr] = -1;
}

void solve() {
    int ptr = 0;
    int score = 0;
    while (a[ptr] != -1) {
        if (is_free(ptr)) {
            score ^= 1;
            int next_ptr = back[ptr];
            remove(ptr);
            ptr = next_ptr;
        } else {
            ptr = forw[ptr];
        }
    }

    printf("%s\n", score ? "Alice" : "Bob");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T-- > 0) {
        read();
        solve();
    }

    return 0;
}
