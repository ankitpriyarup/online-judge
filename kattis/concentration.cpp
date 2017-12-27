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

constexpr int MAXN = 2 * 1000006;
int n;
int a[2][MAXN];

int ptrs[2];
int scores[2];
set<int> known;

int pull(bool player) {
    while (known.find(a[player][ptrs[player]]) != end(known)) {
        ++ptrs[player];
    }

    int card = a[player][ptrs[player]];
    known.insert(card);

    // printf("Player %d pulled %d\n", player, card);
    return card;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    scanf("%d", &n);
    n *= 2;
    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[k][i]);
        }
    }

    int rem = n;
    int player = 0;
    int num_pairs = 0;
    priority_queue<pair<int, int> > pq;

    while (rem) {
        if (num_pairs) {
            scores[player] += num_pairs;
            rem -= 2 * num_pairs;
            num_pairs = 0;
        } else {
            int c1 = pull(player);
            if (known.find(c1 ^ 1) != end(known)) {
                scores[player]++;
                rem -= 2;
            } else {
                int c2 = pull(player);
                if ((c1 ^ 1) == c2) {
                    scores[player]++;
                    rem -= 2;
                } else {
                    if (known.find(c2 ^ 1) != end(known)) {
                        ++num_pairs;
                    }
                    player = 1 - player;
                }
            }
        }
    }

    if (scores[0] > scores[1]) {
        printf("%d\n", 0);
    } else if (scores[1] > scores[0]) {
        printf("%d\n", 1);
    } else {
        printf("%d\n", -1);
    }
    
    return 0;
}
