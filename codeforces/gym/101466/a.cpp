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

constexpr int MAXN = 1e6 + 6;
constexpr int LEN = 20;
int trie[LEN * MAXN][10];
int trie_len = 1;

void insert(const string& s) {
    assert(s.size() == LEN);
    int node = 0;
    for (int i = 0; i < LEN; ++i) {
        int dig = s[i] - '0';
        if (!trie[node][dig]) {
            trie[node][dig] = trie_len++;
        }

        node = trie[node][dig];
    }
}

string min_query(const string& s) {
    assert(s.size() == LEN);
    string t;
    int node = 0;
    for (int i = 0; i < LEN; ++i) {
        int dig = s[i] - '0';
        int follow = -1;
        for (int val = 0; val < 10; ++val) {
            int need = (10 + val - dig) % 10;
            if (trie[node][need]) {
                follow = need;
                break;
            }
        }

        assert(follow != -1);
        t.push_back('0' + ((dig + follow) % 10));
        node = trie[node][follow];
    }

    return t;
}

string max_query(const string& s) {
    assert(s.size() == LEN);
    string t;
    int node = 0;
    for (int i = 0; i < LEN; ++i) {
        int dig = s[i] - '0';
        int follow = -1;
        for (int val = 9; val >= 0; --val) {
            int need = (10 + val - dig) % 10;
            if (trie[node][need]) {
                follow = need;
                break;
            }
        }

        assert(follow != -1);
        t.push_back('0' + ((dig + follow) % 10));
        node = trie[node][follow];
    }

    return t;
}


void strip_lead(string& s) {
    reverse(begin(s), end(s));
    while (!s.empty() and s.back() == '0') {
        s.pop_back();
    }

    reverse(begin(s), end(s));
    if (s.empty())
        s.push_back('0');
}

void pad(string& s) {
    string buf = "";
    while (s.size() + buf.size() < LEN)
        buf.push_back('0');

    s = buf + s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string min_ans, max_ans;
    for (int i = 0; i < LEN; ++i) {
        min_ans.push_back('9');
        max_ans.push_back('0');
    }

    string s;
    cin >> s;
    pad(s);
    insert(s);

    for (int i = 1; i < n; ++i) {
        cin >> s;
        pad(s);
        min_ans = min(min_ans, min_query(s));
        max_ans = max(max_ans, max_query(s));

        insert(s);
    }

    strip_lead(min_ans);
    strip_lead(max_ans);

    cout << min_ans << ' ' << max_ans;

    return 0;
}
