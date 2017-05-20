#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<long long, double> memo;

inline int remove_ball(int balls, int index) {
    int right_mask = (1 << index) - 1;
    int left_part = (balls & ~right_mask) >> (index + 1);
    int right_part = (balls & right_mask);

    return (left_part << index) | right_part;
}

inline bool get_ball(int balls, int index) {
    return balls & (1 << index);
}

// returns the expected number of white balls 
double ev(int balls, int total_balls, int moves) {
    if (moves == 0) {
        return 0.0;
    }

    int white_count = __builtin_popcount(balls);
    if (white_count == 0) {
        return 0.0;
    }
    
    if (white_count == total_balls) {
        return moves;
    }
    
    if (total_balls == moves) {
        return white_count;
    }
    
    long long state = ((long long) balls) << 32 | total_balls;
    
    if (memo.find(state) != memo.end()) {
        return memo[state];
    }
    
    int left = 0;
    int right = total_balls - 1;
    
    double ans = 0;
    double prob = 1.0 / total_balls;
    double two_prob = 2.0 / total_balls;

    while (left <= right) {
        double left_white = get_ball(balls, left);
        double right_white = get_ball(balls, right);

        if (left == right) {
            ans += prob * (left_white + ev(remove_ball(balls, left), total_balls - 1, moves - 1));
        } else {
            double left_ev = left_white + ev(remove_ball(balls, left), total_balls - 1, moves - 1);
            double right_ev = right_white + ev(remove_ball(balls, right), total_balls - 1, moves - 1);

            ans += two_prob * max(left_ev, right_ev);
        }

        ++left;
        --right;
    }

    memo[state] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int num_balls, moves;
    char balls_str[33];
    
    scanf("%d %d", &num_balls, &moves);
    scanf("%s", balls_str);

    int balls = 0;
    for (int i = 0; i < num_balls; ++i) {
        balls <<= 1;
        balls += (balls_str[i] == 'W');
    }
    
    double ans = ev(balls, num_balls, moves);
    
    printf("%.10f\n", ans);

    return 0;
}
