#include <iostream>

using namespace std;

int ans[151][6];
int denom[] = {5, 5, 10, 15, 20};

int main() {
    for (int i = 0; i < 5; ++i) {
        ans[0][i] = 0;
    }

    for (int i = 1; i < 151; ++i) {
        for (int j = 0; j < 5; ++j) {
            ans[i][j] = j == 0 ? 0 : ans[i][j - 1];
            if (denom[j] > i) {
                break;
            }

            ans[i][j] += ans[i - denom[j]][j];
        }
    }

    for (int i = 0; i < 5; ++i) {
        cout << ans[5][i] << '\n';
    }

    return 0;
}
