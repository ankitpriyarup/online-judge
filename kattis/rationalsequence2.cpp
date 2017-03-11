#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int num_cases;
    cin >> num_cases;

    int k;
    string s;
    while (num_cases-- > 0) {
        cin >> k >> s;

        int slash_pos = s.find('/');
        int p = stoi(s.substr(0, slash_pos));
        int q = stoi(s.substr(slash_pos + 1));

        stack<int> vals;

        while (p != q) {
            if (p > q) {
                vals.push(1);
                p -= q;
            } else {
                vals.push(0);
                q -= p;
            }
        }

        vals.push(1);

        long long ans = 0;
        while (!vals.empty()) {
            ans <<= 1LL;
            ans += vals.top();
            vals.pop();
        }

        cout << k << ' ' << ans << '\n';
    }

    return 0;
}
