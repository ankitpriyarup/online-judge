#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 40002;
const int BLOCK_SIZE = 301;

int n;
int a[MAXN];

// Modulo i, in bucket j, how many values are equal to k?
int bucket_freq[BLOCK_SIZE][BLOCK_SIZE][BLOCK_SIZE];

// List of occurences of i
vector<int> freq[MAXN];

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

int big_query(const int& l, const int& r, const int& x, const int& y) {
    int ans = 0;
    for (int v = y; v < MAXN; v += x) {
        ans += upper_bound(freq[v].begin(), freq[v].end(), r) - upper_bound(freq[v].begin(), freq[v].end(), l);
    }

    return ans;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);

    // O(n * b)
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);

        freq[a[i]].push_back(i);
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
