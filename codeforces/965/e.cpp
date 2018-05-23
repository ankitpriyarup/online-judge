#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;
using ll = long long;

constexpr int MAXN = 100345;
constexpr int SIGMA = 26;
int n;
char word[MAXN];
bool end_word[MAXN];
int trie[MAXN][SIGMA];
int nodes = 0;

set<pair<int, int> >* dp[MAXN];
set<pair<int, int> > raw[MAXN];

void solve(int u, int dep = 0) {
    int big_child = -1;
    for (int idx = 0; idx < SIGMA; ++idx) {
        if (trie[u][idx]) {
            solve(trie[u][idx], dep + 1);
            if (big_child == -1 or dp[trie[u][idx]]->size() > dp[big_child]->size()) {
                big_child = trie[u][idx];
            }
        }
    }

    if (big_child == -1) {
        dp[u] = &raw[u];
    } else {
        dp[u] = dp[big_child];
        for (int idx = 0; idx < SIGMA; ++idx) {
            if (trie[u][idx] and trie[u][idx] != big_child) {
                for (auto& p : *dp[trie[u][idx]]) {
                    dp[u]->insert(p);
                }
            }
        }
    }

    if (end_word[u]) {
        dp[u]->emplace(dep, u);
    } else {
        if (dep and !dp[u]->empty()) {
            auto it = prev(end(*dp[u]));
            dp[u]->erase(it);
            dp[u]->emplace(dep, u);
        }
    }
}

void insert(int node, int idx) {
    if (word[idx] == '\0') {
        end_word[node] = true;
        return;
    }

    if (!trie[node][word[idx] - 'a']) {
        trie[node][word[idx] - 'a'] = ++nodes;

        assert(nodes < MAXN);
    }

    insert(trie[node][word[idx] - 'a'], idx + 1);
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        scanf(" %s", word);
        insert(0, 0);
    }

    ll ans = 0LL;
    solve(0);
    for (auto p : *dp[0]) {
        ans += p.first;
    }

    printf("%lld\n", ans);

    return 0;
}
