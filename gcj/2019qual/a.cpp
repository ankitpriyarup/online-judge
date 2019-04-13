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

    int T;
    cin >> T;
    int tc = 1;
    while (T-- > 0) {
        string a;
        cin >> a;
        int n = a.size();

        string s(n, '0'), t(n, '0');
        for (int i = 0; i < n; ++i) {
            if (a[i] == '4') {
                s[i] = '3';
                t[i] = '1';
            } else {
                s[i] = a[i];
            }
        }

        int x = 0;
        while (t[x] == '0')  {
            ++x;
        }

        cout << "Case #" << tc++ << ": " << s << ' ' << t.substr(x) << '\n';
    }
    
    return 0;
}
