#include <iostream>

using namespace std;

string table[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

string convert(char x) {
    string ans = "";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < (int)table[i].size(); ++j) {
            if (x == table[i][j]) {
                char c = i + '0';
                for (int k = 0; k <= j; ++k) {
                    ans += c;
                }

                return ans;
            }
        }
    }
    return "";
}

int main() {
    int N;
    string s;
    cin >> N;
    getline(cin, s);
    int c = 1;
    while (N-- > 0) {
        getline(cin, s);

        string ans;
        for (int i = 0; i < (int)s.size(); ++i) {
            string t = convert(s[i]);
            if (ans.size() > 0 && t[0] == ans[ans.size() - 1]) {
                ans += " ";
            }
            ans += t;
        }

        cout << "Case #" << c++ << ": " << ans << '\n';
    }
    return 0;
}
