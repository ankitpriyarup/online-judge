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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector<pii> waste(k);
    for (int i = 0; i < k; ++i) {
        cin >> waste[i].first >> waste[i].second;
        --waste[i].first;
        --waste[i].second;
    }

    sort(begin(waste), end(waste));
    vector<pair<pii, int>> queries(t);
    for (int i = 0; i < t; ++i) {
        cin >> queries[i].first.first >> queries[i].first.second;
        --queries[i].first.first;
        --queries[i].first.second;
        queries[i].second = i;
    }

    sort(begin(queries), end(queries));
    vector<int> ans(t);

    int ptr = 0;
    for (auto& p : queries) {
        pii pos = p.first;
        int idx = p.second;

        /*
         * cout << "pos: " << pos.first << ", " << pos.second << "\n";
        cout << "idx: " << idx << '\n';
        cout << "ptr: " << ptr << '\n';
        */

        while (ptr < k and waste[ptr] < pos) {
            ++ptr;
        }

        // cout << "pptr: " << ptr << '\n';
        if (ptr < k and waste[ptr] == pos) {
            ans[idx] = 3;
        } else {
            int tot = m * pos.first + pos.second;
            tot -= ptr;
            ans[idx] = tot % 3;
        }
    }

    // cout << "DONE!\n";

    vector<string> res = {"Carrots", "Kiwis", "Grapes", "Waste"};
    for (int x : ans)
        cout << res[x] << '\n';
    
    return 0;
}
