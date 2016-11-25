#include <iostream>

using namespace std;

long long grid[3][3];

int main() {
    int T;

    cin >> T;
    while (T-- > 0) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> grid[i][j];
            }
        }

        long long ans = 0;
        for (int i = 0; i < 3; ++i) {
            long long sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += grid[i][j];
            }

            if (sum % 2 == 0) --sum;
            ans = max(ans, sum);
        }

        for (int i = 0; i < 3; ++i) {
            long long sum = 0;
            for (int j = 0; j < 3; ++j) {
                sum += grid[j][i];
            }

            if (sum % 2 == 0) --sum;

            ans = max(ans, sum);
        }

        cout << ans << '\n';
    }

    return 0;
}
