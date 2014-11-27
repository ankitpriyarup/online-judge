#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

int M, S;
char min_val[101];
char max_val[101];

void find_min(int M, int S) {
    int sum = S;
    for (int i = 0; i < M; i++) {
//        cout << M << " " << S << '\n';
        if (sum == 0) {
            min_val[i] = '0'; 
        } else {
            int digits_left = M - i - 1;
            int max_sum_left = digits_left * 9;
//            cout << "digits_left: " << digits_left << '\n';
//            cout << "max_sum_left: " << max_sum_left << '\n';
            if (sum <= max_sum_left) {
                min_val[i] = (i == 0 ? '1' : '0');
                sum -= (i == 0 ? 1 : 0);
            } else {
                int diff = sum - max_sum_left;
//                cout << "diff: " << diff << '\n';
                if (diff > 9) {
                    min_val[0] = '0';
                    return;
                } else {
                    min_val[i] = '0' + diff;
                    sum -= diff;
                }
            }
        }
    }
}

void find_max(int M, int S) {
    int sum = S;
    for (int i = 0; i < M; i++) {
        if (sum > 9) {
            max_val[i] = '9';
            sum -= 9;
        } else {
            max_val[i] = '0' + sum;
            sum = 0;
        }
    }
}

int main() {
    cin >> M >> S;
    if (M == 1) {
        if (S <= 9) {
            cout << S << " " << S << '\n';
        } else {
            cout << "-1 -1" << '\n';
        }
    } else {
        find_min(M, S);
        find_max(M, S);
        if (min_val[0] == '0' || max_val[0] == '0') {
            cout << "-1 -1";
        } else {
            for (int i = 0; i < M; i++) {
                cout << min_val[i];
            }
            cout << ' ';
            for (int i = 0; i < M; i++) {
                cout << max_val[i];
            }
        }
        cout << '\n';
    }
    return 0;
}
