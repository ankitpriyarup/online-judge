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

    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    reverse(all(a));
    reverse(all(b));

    string aa, bb;
    for (int i = 0; i < min(n, m); ++i) {
        if (a[i] >= b[i]) {
            aa.push_back(a[i]);
        } 
        if (a[i] <= b[i]) {
            bb.push_back(b[i]);
        }
    }

    for (int i = min(n, m); i < max(n, m); ++i) {
        if (i < n) {
            aa.push_back(a[i]);
        } else {
            bb.push_back(b[i]);
        }
    }

    while (aa.size() > 1 and aa.back() == '0') {
        aa.pop_back();
    }
    while (bb.size() > 1 and bb.back() == '0') {
        bb.pop_back();
    }

    reverse(all(aa));
    reverse(all(bb));

    cout << (aa.empty() ? "YODA" : aa) << '\n';
    cout << (bb.empty() ? "YODA" : bb) << '\n';
    
    return 0;
}
