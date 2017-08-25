#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <utility>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

constexpr int MAXV = 10000;

bitset<MAXV> sieve;
vector<int> primes;
vector<int> graph[MAXV];

void gen_sieve() {
    sieve[0] = 1;
    sieve[1] = 1;

    primes.push_back(2);

    for (int i = 3; i < MAXV; i += 2) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (long long j = 1LL * i * i; j < MAXV; j += 2 * i) {
                sieve[j] = i;
            }
        }
    }
}

int dist(int x, int y) {
    int moves = 0;
    int div = 1;
    for (int i = 0; i < 4; ++i) {
        int a = (x / div) % 10;
        int b = (y / div) % 10;

        if (a != b) {
            ++moves;
        }

        div *= 10;
    }

    return moves;
}

void gen_graph() {
    int n = primes.size();

    for (int i = 0; i < n; ++i) {
        if (primes[i] < 1000) continue;
        for (int j = i + 1; j < n; ++j) {
            int d = dist(primes[i], primes[j]);
            assert(1 <= d and d <= 4);
            if (d <= 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}

inline int ind(const int& x) {
    return lower_bound(begin(primes), end(primes), x) - begin(primes);
}

int shortest_path(int src, int sink) {
    vector<int> dist(primes.size(), MAXV);

    queue<int> q;
    q.push(src);
    dist[src] = 0;

    int level = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz-- > 0) {
            int cur = q.front();
            q.pop();

            if (cur == sink) {
                return dist[cur];
            }

            for (int child : graph[cur]) {
                if (dist[child] == MAXV) {
                    dist[child] = dist[cur] + 1;
                    q.push(child);
                }
            }
        }

        ++level;
    }

    return -1;
}

int main() {
    gen_sieve();
    gen_graph();

    int T;
    scanf("%d", &T);

    int u, v;
    while (T-- > 0) {
        scanf("%d %d", &u, &v);
        int ans = shortest_path(ind(u), ind(v));
        if (ans < 0)
            printf("%s\n", "Impossible");
        else
            printf("%d\n", ans);
    }

    return 0;
}
