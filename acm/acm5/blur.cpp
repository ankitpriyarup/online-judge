/**
 * TODO: This solution is too slow. Use prefix sums to optimize
 *
 */
#include <iostream>
#include <cmath>

using namespace std;

int T, N, M, K;
double B2;
int grid[505][505];

int sample(int r, int c) {
    if (K == 0) {
        if (r >= 0 && c >= 0 && r < N && c < M) {
            return grid[r][c];
        } else {
            return 0;
        }
    }

    int sum = 0;
    for (int i = r - K; i <= r + K; i++) {
        for (int j = c - K; j <= c + K; j++) {
            if (i >= 0 && j >= 0 && i < N && j < M) {
                sum += grid[i][j];
            }
        }
    }

    double avg = sum / B2;
    //cout << '\n' << r << " " << c << " " << sum << " " << avg << '\n';
    return round(avg);
}

int main() {
    cin >> T;
    for (int case_num = 0; case_num < T; case_num++) {
        cin >> N >> M >> K;
        B2 = (2 * K + 1) * (2 * K + 1);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << sample(i, j);
                if (j != M - 1) {
                    cout << " ";
                }
            }
            cout << '\n';
        }
    }

    return 0;
}
