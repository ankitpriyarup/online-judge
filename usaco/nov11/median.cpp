#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int num_cows, min_median;
int prefix[100005];
int fenwick[200005];

const int ZERO = 100001;

int read(int x) {
    int count = 0;
    int idx = x + ZERO;
    while (idx > 0) {
        count += fenwick[idx];
        idx -= (idx & -idx);
    }

    return count;
}

void add(int x) {
    int idx = x + ZERO;
    while (idx < 200005) {
        ++fenwick[idx];
        idx += (idx & -idx);
    }
}

int main() {
    freopen("median.in", "r", stdin);
    freopen("median.out", "w", stdout);

    cin >> num_cows >> min_median;

    int x;
    prefix[0] = 0;
    for (int i = 0; i < num_cows; ++i) {
        cin >> x;
        x = (x >= min_median ? 1 : -1);
        prefix[i + 1] = x + prefix[i];
    }

    // Find the number of contiguous subsequences where the sum is >= 0
    /*
     * 10 5 6 2
     * 1 -1 1 -1
     * 0 1 0 1 0
     */
    // For each number, add the number of values <= to it.
    // Easy application of a fenwick tree
    long long ans = 0LL;
    add(0);
    for (int i = 1; i <= num_cows; ++i) {
        int full_prefix = prefix[i];
        ans += read(full_prefix);
        add(full_prefix);
    }

    cout << ans << '\n';

    return 0;
}
