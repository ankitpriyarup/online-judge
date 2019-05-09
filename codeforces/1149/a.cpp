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
    int ones = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 1)
            ++ones;
    }

    int twos = n - ones;
    // if you have a one and a two
    // start with two then one then twos then ones
    // otherwise its fixed
    vector<int> res;
    if (ones > 0 and twos > 0) {
        res.push_back(2);
        res.push_back(1);
        --twos;
        --ones;
    }

    while (twos > 0) {
        res.push_back(2);
        --twos;
    }
    while (ones > 0) {
        res.push_back(1);
        --ones;
    }

    for (int x : res) {
        cout << x << ' ';
    }
    
    return 0;
}
