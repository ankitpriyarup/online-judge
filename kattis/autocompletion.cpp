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

constexpr int SIGMA = 26;

vector<vector<int>> trie_data;
map<int, string> trie_ends;
vector<vector<int>> child_words;

void init() {
    trie_data.assign(1, vector<int>(SIGMA, 0));
    child_words.resize(1);
}

int add_node() {
    int id = trie_data.size();
    trie_data.push_back(vector<int>(SIGMA, 0));
    child_words.push_back(vector<int>());

    return id;
}

void insert(const string& s) {
    int node = 0;
    for (int i = 0; i < s.size(); ++i) {
        int idx = s[i] - 'a';
        if (!trie_data[node][idx]) {
            trie_data[node][idx] = add_node();
        }

        node = trie_data[node][idx];
    }

    trie_ends[node] = s;
}

void recurse(int node) {
    for (int idx = 0; idx < SIGMA; ++idx) {
        if (trie_data[node][idx]) {
            int child_node = trie_data[node][idx];
            recurse(child_node);
            auto it = trie_ends.find(child_node);
            if (it != end(trie_ends)) {
                child_words[node].emplace_back(child_node);
            }

            for (const auto& p : child_words[child_node]) {
                child_words[node].push_back(p);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s;
    init();
    for (int i = 0; i < n; ++i) {
        cin >> s;
        insert(s);
    }

    recurse(0);

    int q;
    cin >> q;
    while (q-- > 0) {
        cin >> s;
        int m = s.size();

        int node = 0;
        string ans;
        for (int i = 0; i < m;) {
            if (s[i] == '#') {
                int hashes = 0;
                while (i < m and s[i] == '#') {
                    ++hashes;
                    ++i;
                }
                if (node != -1 and !child_words[node].empty()) {
                    --hashes;
                    hashes %= child_words[node].size();
                    node = child_words[node][hashes];
                    ans = trie_ends[node];
                }
            } else {
                ans.push_back(s[i]);
                if (node != -1 and trie_data[node][s[i] - 'a']) {
                    node = trie_data[node][s[i] - 'a'];
                } else {
                    node = -1;
                }

                ++i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
