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

map<string, vector<string> > groups;
void parse_group() {
    string name;
    cin >> name;
    vector<string> members;
    string s;
    int k;
    cin >> k;
    while (k-- > 0) {
        cin >> s;
        members.push_back(s);
    }
    sort(begin(members), end(members));
    groups[name] = members;
}

vector<string> parse(const string& cmd) {
    string a, b;
    if (cmd == "union") {
        cin >> a;
        vector<string> s1 = parse(a);
        cin >> b;
        vector<string> s2 = parse(b);

        vector<string> res;
        merge(begin(s1), end(s1), begin(s2), end(s2), back_inserter(res));

        res.erase(unique(begin(res), end(res)), end(res));
        return res;
    } else if (cmd == "intersection") {
        cin >> a;
        vector<string> s1 = parse(a);
        cin >> b;
        vector<string> s2 = parse(b);
        vector<string> res;
        int p1 = 0;
        int p2 = 0;
        int n1 = s1.size();
        int n2 = s2.size();

        while (p1 < n1 and p2 < n2) {
            if (s1[p1] < s2[p2]) {
                ++p1;
            } else if (s1[p1] > s2[p2]) {
                ++p2;
            } else {
                res.push_back(s1[p1]);
                ++p1;
                ++p2;
            }
        }

        res.erase(unique(begin(res), end(res)), end(res));
        return res;
    } else if (cmd == "difference") {
        cin >> a;
        vector<string> s1 = parse(a);
        cin >> b;
        vector<string> s2 = parse(b);
        vector<string> res;
        int p1 = 0;
        int p2 = 0;
        int n1 = s1.size();
        int n2 = s2.size();

        while (p1 < n1) {
            if (p2 >= n2 or s1[p1] < s2[p2]) {
                res.push_back(s1[p1]);
                ++p1;
            } else if (p2 < n2 and s1[p1] > s2[p2]) {
                ++p2;
            } else {
                ++p1;
                ++p2;
            }
        }

        res.erase(unique(begin(res), end(res)), end(res));
        return res;
    } else {
        return groups[cmd];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string cmd;
    while (cin >> cmd) {
        if (cmd == "group") {
            parse_group();
        } else {
            vector<string> res = parse(cmd);
            if (res.empty()) {
                cout << '\n';
                continue;
            }
            cout << res[0];
            for (size_t i = 1; i < res.size(); ++i) {
                cout << ' ' << res[i];
            }
            cout << '\n';
        }
    }

    return 0;
}
