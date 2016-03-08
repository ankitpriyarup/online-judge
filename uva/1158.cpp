#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <utility>

using namespace std;

int N;
int knapsack[400005];
set<int> edges;

void solve() {
    memset(knapsack, -1, sizeof(knapsack));
    knapsack[0] = 0;
    for (int i = 1; i <= 400000; ++i) {
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            int val = *it;
            if (val > i) {
                break;
            }

            int cost = knapsack[i - val] + 1;
            if (knapsack[i] == -1 || cost < knapsack[i])
                knapsack[i] = cost;
        }
    }
}

int main() {
    long long total = 0LL;
    for (int i = 1; min(1LL * i * i * i, total) <= 400000; ++i) {
        int sq = i * i;
        total += sq;
        edges.insert(sq * i);
        edges.insert(total);
    }

    solve();

    cin >> N;
    while (N > -1) {
        cout << knapsack[N] << '\n';
        cin >> N;
    }
    return 0;
}
