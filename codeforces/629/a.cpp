#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    char grid[102][102];

    long long ans = 0LL;
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        int count = 0;
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 'C')
                ++count;
        }

        ans += 1LL * count * (count - 1) / 2;
    }

    for (int j = 0; j < N; ++j) {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (grid[i][j] == 'C')
                ++count;
        }

        ans += 1LL * count * (count - 1) / 2;
    }

    cout << ans << '\n';
    return 0;
}
