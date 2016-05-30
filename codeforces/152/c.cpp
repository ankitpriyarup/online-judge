#include <iostream>
#include <cstring>

using namespace std;

char grid[101][101];
bool seen[30];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    long long ans = 1;
    for (int j = 0; j < m; ++j) {
        memset(seen, 0, sizeof(seen));
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!seen[grid[i][j] - 'A']) {
                seen[grid[i][j] - 'A'] = true;
                ++count;
            }
        }
        ans *= count;
        ans %= 1000000007;
    }

    cout << ans << '\n';
    return 0;
}
