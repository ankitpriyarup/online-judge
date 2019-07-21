#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

string ans[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

bool is_leap(int i) {
    return i % 400 == 0 or (i % 4 == 0 and i % 100 != 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int y = 1867;
    int n;
    cin >> n;
    int d = 0;
    for (int i = 0; i < n; ++i) {
        ++d;
        if (is_leap(y + i + 1)) {
            ++d;
        }

        d %= 7;
    }

    cout << ans[d] << '\n';
    
    return 0;
}
