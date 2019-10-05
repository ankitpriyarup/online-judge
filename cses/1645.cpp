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

    int n;
    cin >> n;
    vector<pii> stk = {{-1, 0}};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        while (stk.back().first > x) {
            stk.pop_back();
        }
        cout << stk.back().second << ' ';
        stk.emplace_back(x, i + 1);
    }
    
    return 0;
}
