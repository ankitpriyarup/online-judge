#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

#define ZERO 57000

using namespace std;

int T;
int rhs;
int N;
int A[200];

bool dp[100][124000];

int main() {
    cin >> T;
    while (T-- > 0) {
        int i = 0;
        cin >> A[i];
        char c;
        while (true) {
            cin >> c;
            if (c == '=') {
                cin >> rhs;
                break;
            }
            cin >> A[++i];
        }
        N = i + 1;

        int correct_sum = A[0];
        for (int i = 1; i < N; i++) {
            correct_sum -= A[i];
        }

        if (correct_sum == rhs) {
            cout << "correct" << endl;
        } else {
            memset(dp, 0, sizeof(dp));
            dp[1][A[0] - A[1] + ZERO] = true;
            for (int i = 2; i < N; i++) {
                for (int j = -57000; j < 57000; j++) {
                    dp[i][j + ZERO] = dp[i - 1][j - A[i] + ZERO] | dp[i - 1][j + A[i] + ZERO];
                }
            }

            if (dp[N - 1][rhs + ZERO]) {
                cout << "fixable" << endl;
            } else {
                cout << "unfixable" << endl;
            }
        }
    }

    return 0;
}
