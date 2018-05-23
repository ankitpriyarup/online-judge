#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int MAXN = 100005;
int n, l;
int a[MAXN];
int at[MAXN];

int works(int x) {
    int ptr = 0;
    memset(at, 0, sizeof(at));
    at[0] = x;
    int rptr = 1;
    while (ptr < n) {
        while (ptr < n and at[ptr] == 0)
            ++ptr;
        if (ptr == n) break;

        // printf("moving %d frogs from %d\n", at[ptr], 0);
        rptr = max(ptr + 1, rptr);
        while (at[ptr] > 0 and rptr <= min(n, ptr + l)) {
            // printf("Trying stone %d with cap %d and curr %d\n", rptr, a[rptr], at[rptr]);
            assert(a[rptr] >= at[rptr]);
            int cap = a[rptr] - at[rptr];
            int moved = min(cap, at[ptr]);
            // printf("hopped (cap %d) %d from %d to %d\n", cap, moved, ptr, rptr);
            at[ptr] -= moved;
            at[rptr] += moved;
            if (a[rptr] == at[rptr])
                ++rptr;
        }

        if (at[ptr] != 0) {
            return false;
        }
    }

    return at[n] == x;
}

int main() {
    scanf(" %d %d", &n, &l);
    for (int i = 1; i < n; ++i) {
        scanf(" %d", &a[i]);
    }
    a[n] = 1e9 + 9;

    int lo = 0;
    int hi = 1e9 + 7;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (works(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    printf("%d\n", lo);

    return 0;
}
