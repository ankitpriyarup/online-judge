#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
 
    string alpha = "abc";
 
    do {
        {
            // abcabcabc
            string w = n == 1 ? alpha : alpha + alpha;
            bool valid = w.find(s) == string::npos and w.find(t) == string::npos;
            if (valid) {
                string res;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        res.push_back(alpha[j]);
                    }
                }
 
                cout << "YES\n";
                cout << res << '\n';
                return 0;
            }
        }
        {
            // aaabbbccc
            if (s[0] == s[1] or t[0] == t[1]) {
                continue;
            }
            if (alpha.find(s) == string::npos and alpha.find(t) == string::npos) {
                string res;
                for (int j = 0; j < 3; ++j) {
                    for (int i = 0; i < n; ++i) {
                        res.push_back(alpha[j]);
                    }
                }
 
                cout << "YES\n";
                cout << res << '\n';
                return 0;
            }
        }
    } while (next_permutation(begin(alpha), end(alpha)));
 
    cout << "NO\n";
 
    return 0;
}
