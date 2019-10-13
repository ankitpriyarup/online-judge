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

    char op;
    cin >> op;
    int s;
    cin >> s;
    if (op == 'D') {
        s = -s;
    }

    string msg;
    cin >> msg;
    for (int i = 0; i < msg.size(); ++i) {
        int x = msg[i] - 'a';
        x += s;
        x = (x + 26) % 26;

        msg[i] = (x + 'a');
    }

    cout << msg << '\n';
    
    return 0;
}
