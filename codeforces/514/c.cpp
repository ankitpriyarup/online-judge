#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 300005;
constexpr int NODES = 2 * MAXN;
int n, q;
string words[MAXN];
int trie[NODES][3];
bool is_word[NODES];
int nodes = 1;

void insert(const string& s) {
    int node = 0;
    for (int i = 0; i < s.size(); ++i) {
        int& child = trie[node][s[i] - 'a'];
        if (child == -1) {
            child = nodes++;
        }

        node = child;
    }

    is_word[node] = true;
}

bool contains(const string& s, int node = 0, int idx = 0, bool exact = false) {
    if (node == -1) return false;
    if (idx == s.size()) {
        return exact && is_word[node];
    }

    if (exact) {
        return contains(s, trie[node][s[idx] - 'a'], idx + 1, exact);
    } else {
        bool ans = false;
        for (int i = 0; !ans and i < 3; ++i) {
            if (i == s[idx] - 'a') {
                ans |= contains(s, trie[node][i], idx + 1, false);
            } else {
                ans |= contains(s, trie[node][i], idx + 1, true);
            }
        }

        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(trie, -1, sizeof(trie));

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        insert(words[i]);
    }

    string s;
    while (q-- > 0) {
        cin >> s;

        bool found = contains(s);

        cout << (found ? "YES" : "NO") << '\n';
    }

    return 0;
}
