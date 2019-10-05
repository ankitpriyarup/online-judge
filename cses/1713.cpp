#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e6 + 1;
int num_div[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            ++num_div[j];
        }
    }

    int T;
    cin >> T;
    while (T-- > 0) {
        int x;
        cin >> x;
        cout << num_div[x] << '\n';
    }
    
    return 0;
}
