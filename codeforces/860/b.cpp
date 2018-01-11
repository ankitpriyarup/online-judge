#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;
using ll = long long;

constexpr int MAXN = 70004;
int n;
string s[MAXN];
map<int, int> freq[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int len = 1; len <= 9; ++len) {
            set<int> my_subs;
            for (int start = 0; start + len <= 9; ++start) {
                string sub = s[i].substr(start, len);
                my_subs.insert(stoi(sub));
            }

            for (auto x : my_subs) {
                ++freq[len][x];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int len = 1; !found and len <= 9; ++len) {
            for (int start = 0; !found and start + len <= 9; ++start) {
                string val = s[i].substr(start, len);
                if (freq[len][stoi(val)] == 1) {
                    cout << val << '\n';
                    found = true;
                    break;
                }
            }
        }
    }

    return 0;
}
