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

    string s;
    cin >> s;

    vi score(2, 0);
    vector<string> keys = {"KANGAROO", "KIWIBIRD"};

    for (char c : s) {
        if (c >= 'a') {
            c -= 'a';
            c += 'A';
        }

        for (int k = 0; k < 2; ++k) {
            for (char d : keys[k]) {
                if (c == d) {
                    ++score[k];
                }
            }
        }
    }

    if (score[0] == score[1]) {
        cout << "Feud continues\n";
    } else if (score[0] < score[1]) {
        cout << "Kiwis\n";
    } else {
        cout << "Kangaroos\n";
    }
    
    return 0;
}
