#include <cstdio>

using namespace std;

const int MAXN = 40002;
const int BLOCK_SIZE = 401;

int n;
int a[MAXN];

// Modulo i, in bucket j, how many values are equal to k?
int bucket_freq[BLOCK_SIZE][BLOCK_SIZE][BLOCK_SIZE];

// Overall, how many values in bucket i are equal to j
int big_bucket_freq[BLOCK_SIZE][MAXN];

// O(max(b, n / b))
int small_query(const int& l, const int& r, const int& x, const int& y) {
    int i = l + 1;
    int ans = 0;
    while (i <= r) {
        if (i % BLOCK_SIZE == 0 and i + BLOCK_SIZE - 1 <= r) {
            ans += bucket_freq[x][i / BLOCK_SIZE][y];
            i += BLOCK_SIZE;
        } else {
            ans += ((a[i] % x) == y);
            ++i;
        }
    }

    return ans;
}

int equal(const int& l, const int& r, const int& v) {
    int i = l + 1;
    int ans = 0;

    // O(max(b, n / b))
    while (i <= r) {
        if (i % BLOCK_SIZE == 0 and i + BLOCK_SIZE - 1 <= r) {
            ans += big_bucket_freq[i / BLOCK_SIZE][v];
            i += BLOCK_SIZE;
        } else {
            ans += (a[i] == v);
            ++i;
        }
    }

    return ans;
}

int big_query(const int& l, const int& r, const int& x, const int& y) {
    int ans = 0;
    // O(n / b)
    for (int v = y; v < MAXN; v += x) {
        ans += equal(l, r, v);
    }

    return ans;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);

    // O(n * b)
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);

        big_bucket_freq[i / BLOCK_SIZE][a[i]]++;
        for (int j = 1; j < BLOCK_SIZE; ++j) {
            bucket_freq[j][i / BLOCK_SIZE][a[i] % j]++;
        }
    }

    int l, r, x, y;

    // O(q * n / b * max(b, n / b))
    while (q-- > 0) {
        scanf("%d %d %d %d", &l, &r, &x, &y);
        // l exclusive r inclusive.
        ++r;

        int ans = 0;
        if (x < BLOCK_SIZE) {
            // O(max(b, n / b))
            ans = small_query(l, r, x, y);
        } else {
            // O(n / b * max(b, n / b))
            ans = big_query(l, r, x, y);
        }

        printf("%d\n", ans);
    }

    return 0;
}
