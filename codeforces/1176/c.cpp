#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int good[] = {4, 8, 15, 16, 23, 42};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vi cur(7, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == good[0])
            ++cur[0];

        for (int j = 1; j < 6; ++j) {
            if (good[j] == x) {
                if (cur[j - 1] > 0) {
                    --cur[j - 1];
                    ++cur[j];
                }
                break;
            }
        }
    }

    cout << (n - 6 * cur[5]) << '\n';
    
    return 0;
}
