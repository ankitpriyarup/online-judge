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

int codes[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
constexpr int NODES = 6e6;
int trie[NODES][8];
int children[NODES];
int trie_sz = 1;

void insert(const string& s) {
    int node = 0;
    for (int j = 0; j < (int)s.size(); ++j) {
        int val = codes[s[j] - 'a'] - 2;
        if (!trie[node][val]) {
            trie[node][val] = trie_sz++;
        }

        node = trie[node][val];
        ++children[node];
    }
}

int query(const string& s) {
    int node = 0;
    for (int j = 0; j < (int)s.size(); ++j) {
        int val = s[j] - '0';
        if (val < 2)
            return 0;
        val -= 2;
        if (!trie[node][val])
            return 0;
        node = trie[node][val];
    }
    return children[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    string name;
    while (n-- > 0) {
        cin >> name;
        insert(name);
    }

    while (q-- > 0)  {
        cin >> name;
        cout << query(name) << '\n';
    }
    
    return 0;
}
