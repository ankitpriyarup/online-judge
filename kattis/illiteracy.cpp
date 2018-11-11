#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

inline char rot(char c) {
    return (c == 'F') ? 'A' : c + 1;
}

string do_a(const string& s, int idx) {
    string t(s);
    if (idx > 0) {
        t[idx - 1] = rot(t[idx - 1]);
    }
    if (idx < 7) {
        t[idx + 1] = rot(t[idx + 1]);
    }

    return t;
}

string do_b(const string& s, int idx) {
    if (idx == 0 or idx == 7) {
        return "";
    }
    string t(s);
    t[idx + 1] = t[idx - 1];

    return t;
}

string do_c(const string& s, int idx) {
    string t(s);
    t[7 - idx] = rot(t[7 - idx]);

    return t;
}

string do_d(const string& s, int idx) {
    if (idx == 0 or idx == 7) {
        return "";
    }
    string t(s);
    if (idx <= 3) {
        for (int i = 0; i < idx; ++i) {
            t[i] = rot(t[i]);
        }
    } else {
        for (int i = idx + 1; i < 7; ++i) {
            t[i] = rot(t[i]);
        }
    }

    return t;
}

string do_e(const string& s, int idx) {
    if (idx == 0 or idx == 7) {
        return "";
    }
    string t(s);
    int y = min(idx, 7 - idx);
    t[idx - y] = rot(t[idx - y]);
    t[idx + y] = rot(t[idx + y]);

    return t;
}

string do_f(const string& s, int idx) {
    string t(s);
    int x = idx + 1;
    int y = (x % 2 == 1) ? (x + 9) / 2 : x / 2;
    t[y - 1] = rot(t[y - 1]);
    return t;
}

vector<string> follow(const string& s) {
    vector<string> res;
    for (int i = 0; i < 8; ++i) {
        if (s[i] == 'A') {
            res.push_back(do_a(s, i));
        } else if (s[i] == 'B') {
            res.push_back(do_b(s, i));
        } else if (s[i] == 'C') {
            res.push_back(do_c(s, i));
        } else if (s[i] == 'D') {
            res.push_back(do_d(s, i));
        } else if (s[i] == 'E') {
            res.push_back(do_e(s, i));
        } else if (s[i] == 'F') {
            res.push_back(do_f(s, i));
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0 << '\n';
        return 0;
    }
    queue<string> q;
    q.push(s);
    int dist = 0;
    set<string> seen;
    seen.insert(s);

    while (!q.empty()) {
        int sz = q.size();
        while (sz-- > 0) {
            string c = q.front();
            q.pop();
            for (string& x : follow(c)) {
                if (x == s) continue;

                if (x == t) {
                    cout << (dist + 1) << '\n';
                    return 0;
                }

                if (seen.count(x)) continue;
                seen.insert(x);
                q.push(x);
            }
        }
        ++dist;
    }
    
    return 0;
}
