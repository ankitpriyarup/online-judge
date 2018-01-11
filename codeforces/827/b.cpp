#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 200005;
int n, k;

bool works(long long dist) {
    long long nodes = dist + 1LL;

    long long start = dist / 2LL;
    long long sz = min(start, dist - start);

    nodes += (k - 2LL) * sz;

    return nodes >= n;
}

void print_sol(int dist) {
    for (int i = 2; i <= dist + 1; ++i) {
        printf("%d %d\n", i - 1, i);
    }

    int root = (dist + 2) / 2;
    int node = dist + 2;

    int rem_nodes = n - dist + 1;
    int rem_leaves = k - 2;

    int max_height = min(root - 1, dist + 1 - root);

    vector<int> tips;
    while (rem_leaves-- > 0) {
        printf("%d %d\n", root, node);
        tips.push_back(node);
        node++;
    }

    int ptr = 0;
    while (node <= n) {
        printf("%d %d\n", tips[ptr], node);
        tips[ptr] = node;
        ++node;

        ptr = (ptr + 1) % tips.size();
    }
}

int main() {
    scanf("%d %d", &n, &k);

    int lo = 1;
    int hi = n + 2;

    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        if (works(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    printf("%d\n", hi);
    print_sol(hi);

    return 0;
}
