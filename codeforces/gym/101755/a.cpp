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

    int s, g;
    cin >> s >> g;
    bool valid = s > g and s % g == 0;
    if (valid) {
        cout << (s - g) << ' ' << g << '\n';
    } else {
        cout << "-1\n";
    }

    
    return 0;
}
