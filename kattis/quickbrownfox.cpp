#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

bool seen[26];

int main() {
    int n;
    cin >> n;

    string s;
    getline(cin, s);
    while (n-- > 0) {
        getline(cin, s);

        int l = s.size();
        memset(seen, 0, sizeof(seen));
        for (int i = 0; i < l; ++i) {
            char c = s[i];
            if ('a' <= c and c <= 'z') {
                seen[c - 'a'] = true;
            } else if ('A' <= c and c <= 'Z') {
                seen[c - 'A'] = true;
            }
        }

        string out = "";
        for (int i = 0; i < 26; ++i) {
            if (!seen[i]) {
                out += ('a' + i);
            }
        }

        if (out.size() == 0) {
            cout << "pangram\n";
        } else {
            cout << "missing " << out << "\n";
        }
    }

    return 0;
}
