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
using bs = bitset<100>;

bool cmp(const pair<bs, int>& a, const pair<bs, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }

    auto aa = a.first.to_string();
    auto bb = b.first.to_string();
    return aa < bb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    scanf(" %d", &T);
    while (T-- > 0) {
        int n, m;
        scanf(" %d %d", &n, &m);

        vector<pair<bs, int>> bundles;
        int price, sz;
        int x;
        for (int i = 0; i < m; ++i) {
            scanf(" %d %d", &price, &sz);
            bs bundle;
            while (sz-- > 0) {
                scanf(" %d", &x);
                --x;
                bundle.set(x);
            }

            bundles.emplace_back(bundle, price);
        }

        sort(begin(bundles), end(bundles), cmp);
        vector<pair<bs, int>> pared;
        for (const auto& p : bundles) {
            if (pared.empty() or pared.back().first != p.first) {
                pared.push_back(p);
            }
        }

        /*
        for (const auto& p : pared) {
            for (int i = 0; i < n; ++i) {
                if (p.first[i]) {
                    printf("%d ", i + 1);
                }
            }
            printf(" | %d\n", p.second);
        }
        */

        bs all;
        for (int i = 0; i < n; ++i) {
            all.set(i);
        }
        if (pared.back().first != all) {
            pared.emplace_back(all, 1e9 + 7);
        }

        vector<vector<int>> children(pared.size());
        for (int i = 0; i < pared.size(); ++i) {
            int cost = pared[i].second;
            bs child_mask;
            int sum = 0;
            for (int x : children[i]) {
                child_mask |= pared[x].first;
                sum += pared[x].second;
            }

            if (child_mask == pared[i].first) {
                cost = min(cost, sum);
            }

            for (int j = i + 1; j < pared.size(); ++j) {
                if ((pared[i].first & pared[j].first) == pared[i].first) {
                    children[j].push_back(i);
                    break;
                }
            }

            pared[i].second = cost;
        }

        printf("%d\n", pared.back().second);
    }
    
    return 0;
}
