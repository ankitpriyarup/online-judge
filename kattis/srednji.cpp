#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

constexpr int MAXN = 100005;
int n, b;
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d %d", &n, &b);
    int middle;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", arr + i);
        if (arr[i] == b) {
            middle = i;
        }
    }

    map<int, int> freq;
    int cum_sum = 0;
    for (int i = middle; i <= n; ++i) {
        if (arr[i] > b)
            ++cum_sum;
        else if (arr[i] < b)
            --cum_sum;

        ++freq[cum_sum];
        // printf("Encountered right sum of %d\n", cum_sum);
    }

    ll ans = 0LL;
    cum_sum = 0;
    for (int i = middle; i; --i) {
        if (arr[i] > b)
            ++cum_sum;
        else if (arr[i] < b)
            --cum_sum;

        ans += freq[-cum_sum];
        // printf("Encountered left sum of %d\n", cum_sum);
    }

    printf("%lld\n", ans);

    return 0;
}
