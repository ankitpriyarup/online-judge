#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // greedy decrease down to 1
    // can only ever make odd numbers
    // 1 only goes to 3
    // 3 -> 5 7
    // 5 -> 9 11
    // 7 -> 13 15
    // 5 and 7 come from 3
    // how to check? see what block of 4 you're in
    // n / 4
    // 5 7 -> 3
    // 9 11 -> 5
    // 13 15 -> 7
    // f(x) = 1 + 2 * (x // 4)
    int n;
    cin >> n;
    if (!(n & 1)) {
        cout << "No solution\n";
        return 0;
    }

    vi res;
    res.push_back(n);
    while (res.back() > 1) {
        int y = (res.back() / 4) * 2 + 1;
        res.push_back(y);
    }

    reverse(all(res));
    cout << ((int)res.size() - 1) << '\n';
    for (int i = 0; i + 1 < res.size(); ++i) {
        if ((res[i] << 1) + 1 == res[i + 1]) {
            cout << "2 ";
        } else {
            cout << "1 ";
        }
    }
    cout << '\n';
    
    return 0;
}
