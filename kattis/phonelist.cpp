#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int SIGMA = 10;

struct Trie {
    vector<vector<int>> data;
    vector<int> hits;

    Trie() {
        data.emplace_back(SIGMA, 0);
        hits.push_back(0);
    }

    void insert(string s) {
        int node = 0;
        for (char c : s) {
            int x = c - '0';
            if (!data[node][x]) {
                data[node][x] = data.size();
                data.emplace_back(SIGMA, 0);
                hits.push_back(0);
            }

            node = data[node][x];
        }

        ++hits[node];
    }

    bool solve(int node = 0) {
        bool has_children = false;
        bool res = true;

        for (int d = 0; d < SIGMA; ++d) {
            if (data[node][d]) {
                has_children = true;
                res &= solve(data[node][d]);
            }
        }

        res &= !(has_children and hits[node] > 0);
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while (T-- > 0) {
        int n;
        cin >> n;
        Trie trie;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            trie.insert(s);
        }

        bool valid = trie.solve();
        cout << (valid ? "YES" : "NO") << '\n';
    }

    return 0;
}
