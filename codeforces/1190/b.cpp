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
    vector<int> a(n);
    map<int, int> freq;
    for (auto& x : a) { 
        cin >> x;
        ++freq[x];
    }
    sort(all(a));

    vi doubles;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1]) {
            doubles.push_back(i);
        }
    }

    if (a[1] == 0 or doubles.size() >= 2) {
        cout << "cslnb\n";
        return 0;
    }

    bool valid = false;
    if (doubles.empty() or (a[doubles[0]] != 0 and freq[a[doubles[0]] - 1] == 0)) {
        valid = true;
    }

    bool win = false;
    if (valid) {
        ll diag = 0;
        for (int i = 0; i < n; ++i) {
            diag += a[i] - i;
        }
        win = diag % 2 == 1;
    }

    cout << (win ? "sjfnb" : "cslnb") << '\n';

    return 0;
}
