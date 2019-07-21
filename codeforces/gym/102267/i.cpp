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

    vi ans(n, 0);

    string s;
    cin >> s;
    vi stk;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == ')') {
            stk.pop_back();
            continue;
        } else if (c == '(') {
            continue;
        } else {
            int j = i;
            while (j + 1 < s.size() and '0' <= s[j + 1] and s[j + 1] <= '9') {
                ++j;
            }

            int id = 0;
            for (int k = i; k <= j; ++k) {
                id *= 10;
                id += s[k] - '0';
            }

            if (!stk.empty())
                ans[id - 1] = stk.back();

            stk.push_back(id);
            i = j;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}
