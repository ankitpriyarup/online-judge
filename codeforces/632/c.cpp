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
    vector<string> strings(n);
    for (auto& s : strings) {
        cin >> s;
    }

    sort(all(strings), [](string a, string b) {
        return (a + b) < (b + a);
    });

    for (const string& s : strings) {
        cout << s;
    }
    
    return 0;
}
