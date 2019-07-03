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

    vector<string> words(n);
    for (auto& word : words) {
        cin >> word;
    }

    string goal = words[0];
    for (int i = 1; i < n; ++i) {
        goal.push_back(' ');
        goal += words[i];
    }

    int q;
    cin >> q;

    bool in_caps = false;
    string cur;
    while (q-- > 0) {
        string cmd;
        cin >> cmd;

        if (cmd == "Space") {
            cur.push_back(' ');
        } else if (cmd == "CapsLock") {
            in_caps = !in_caps;
        } else if (cmd == "Backspace") {
            if (!cur.empty()) {
                cur.pop_back();
            }
        } else {
            char c = cmd[0];
            if (in_caps) {
                c = (c - 'a' + 'A');
            }

            cur.push_back(c);
        }
    }

    if (cur == goal) {
        cout << "Correct\n";
    } else {
        cout << "Incorrect\n";
    }
    
    return 0;
}
