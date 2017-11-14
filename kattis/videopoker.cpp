#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int num_ranks = 13;
char ranks[] = "A23456789TJQK";
constexpr int num_suits = 4;
char suits[] = "cdhs";

constexpr int MAXT = 11;
int scores[10];
int hands[MAXT][5];
int hand[5];
int rank_sum[num_ranks];
int suit_sum[num_suits];

int sum_scores[MAXT][1 << 5];
int total_hands[MAXT][1 << 5];
int class_sum[15];

int parse(char rank, char suit) {
    int rank_ind = find(ranks, ranks + num_ranks, rank) - ranks;
    int suit_ind = find(suits, suits + num_suits, suit) - suits;

    return (rank_ind << 2) | suit_ind;
}

void sum_ranks() {
    for (int i = 0; i < num_ranks; ++i) {
        rank_sum[i] = 0;
    }

    for (int i = 0; i < 5; ++i) {
        rank_sum[hand[i] >> 2]++;
    }
}

void sum_suits() {
    for (int i = 0; i < num_suits; ++i) {
        suit_sum[i] = 0;
    }

    for (int i = 0; i < 5; ++i) {
        suit_sum[hand[i] & 3]++;
    }
}

bool straight() {
    bool wrap = (rank_sum[0] > 0);
    for (int i = num_ranks - 1; i >= num_ranks - 4; --i) {
        wrap &= (rank_sum[i] > 0);
    }
    if (wrap) return true;

    int count = 0;
    for (int i = 0; i < 5; ++i) {
        if (rank_sum[i] > 0) ++count;
    }

    if (count == 5) return true;
    for (int i = 5; i < num_ranks; ++i) {
        if (rank_sum[i - 5] > 0) --count;
        if (rank_sum[i] > 0) ++count;
        if (count == 5) return true;
    }

    return false;
}

bool flush() {
    for (int i = 0; i < num_suits; ++i) {
        if (suit_sum[i] == 5) return true;
    }

    return false;
}

bool at_least(int x) {
    for (int i = 0; i < num_ranks; ++i) {
        if (rank_sum[i] >= x) return true;
    }

    return false;
}

bool at_least(int x, int y) {
    for (int i = 0; i < num_ranks; ++i) {
        for (int j = 0; j < num_ranks; ++j) {
            if (i == j) continue;

            if (rank_sum[i] >= x and rank_sum[j] >= y)
                return true;
        }
    }

    return false;
}

int classify() {
    sum_ranks();
    sum_suits();

    if (straight() and flush() and rank_sum[0] > 0 and rank_sum[num_ranks - 1] > 0) {
        return 9;
    } else if (straight() and flush()) {
        return 8;
    } else if (at_least(4)) {
        return 7;
    } else if (at_least(3, 2)) {
        return 6;
    } else if (flush()) {
        return 5;
    } else if (straight()) {
        return 4;
    } else if (at_least(3)) {
        return 3;
    } else if (at_least(2, 2)) {
        return 2;
    } else if (at_least(2)) {
        return 1;
    } else {
        return 0;
    }
}

int get_bitmask(int testcase) {
    int mask = 0;

    for (int i = 0; i < 5; ++i) {
        bool used = false;
        for (int j = 0; j < 5; ++j) {
            used |= (hands[testcase][i] == hand[j]);
        }
        if (used)
            mask |= (1 << i);
    }

    return mask;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    scores[0] = 0;
    for (int i = 1; i <= 9; ++i) {
        scanf("%d", scores + i);
    }

    int T;
    scanf("%d", &T);
    char buf[5];
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%s", buf);
            int card = parse(buf[0], buf[1]);

            hands[i][j] = card;
        }

        /*
        sort(hands[i], hands[i] + 5);
        for (int j = 0; j < 5; ++j) {
            printf("%d ", hands[i][j]);
        }
        printf("\n");
        */
    }

    int total_cards = num_ranks * num_suits;
    for (hand[0] = 0; hand[0] < total_cards; ++hand[0]) {
        for (hand[1] = hand[0] + 1; hand[1] < total_cards; ++hand[1]) {
            for (hand[2] = hand[1] + 1; hand[2] < total_cards; ++hand[2]) {
                for (hand[3] = hand[2] + 1; hand[3] < total_cards; ++hand[3]) {
                    for (hand[4] = hand[3] + 1; hand[4] < total_cards; ++hand[4]) {
                        int klass = classify();
                        int score = scores[klass];
                        ++class_sum[klass];

                        /*
                        for (int i = 0; i < 5; ++i){
                            printf("%d ", hand[i]);
                        }
                        printf("Has score %d\n", score);
                        */

                        for (int i = 0; i < T; ++i) {
                            int bitmask = get_bitmask(i);
                            sum_scores[i][bitmask] += score;
                            total_hands[i][bitmask]++;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < T; ++i) {
        ld best = -10;
        for (int mask = 0; mask < (1 << 5); ++mask) {
            if (total_hands[i][mask])
                best = max(best, 1.0L * sum_scores[i][mask] / total_hands[i][mask]);
        }

        printf("%.17Lf\n", best);
    }

    /*
    printf("CLASS SUMS:\n");
    for (int i = 0; i <= 10; ++i) {
        printf("%d ", class_sum[i]);
    }
    printf("\n");
    */

    return 0;
}
