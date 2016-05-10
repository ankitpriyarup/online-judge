#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    vector<pair<char, int> > v;

    char cur = s[0];
    int len = 1;
    for (int i = 1; i < N; ++i) {
        if (s[i] == cur) {
            ++len;
        } else {
            v.push_back(make_pair(cur, min(len, 2)));
            cur = s[i];
            len = 1;
        }
    }
    v.push_back(make_pair(cur, min(len, 2)));
    bool cleave = false;

    for (auto it = v.begin(); it != v.end(); ++it) {
        //cout << it->first << ' ' << it->second << '\n';
        if (cleave) {
            cout << it->first;
            cleave = false;
        } else {
            for (int i = 0; i < it->second; ++i) {
                cout << it->first;
            }
            if (it->second == 2) {
                cleave = true;
            }
        }
    }

    return 0;
}
