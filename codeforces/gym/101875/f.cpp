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

set<ll> v_union(const vector<vector<ll>>& v) {
    set<ll> res;
    for (const vector<ll>& row : v) {
        res.insert(begin(row), end(row));
    }

    return res;
}

set<ll> v_intersect(const vector<vector<ll>>& v) {
    set<ll> res(begin(v[0]), end(v[0]));
    for (int i = 1; i < v.size(); ++i) {
        set<ll> nxt;
        for (ll x : v[i]) {
            auto it = res.find(x);
            if (it != end(res)) {
                nxt.insert(x);
            }
        }

        swap(res, nxt);
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    scanf(" %d", &n);
    vector<vector<ll>> likes;
    vector<vector<ll>> hates;

    int kind, k;
    for (int i = 0; i < n; ++i) {
        scanf(" %d %d", &kind, &k);
        vector<ll> v(k);
        for (int j = 0; j < k; ++j) {
            scanf(" %lld", &v[j]);
        }

        if (kind == 1) {
            likes.push_back(v);
        } else {
            hates.push_back(v);
        }
    }

    if (likes.empty()) {
        set<ll> some_hate = v_union(hates);
        printf("%lld\n", static_cast<ll>(1e18) - some_hate.size());
    } else if (hates.empty()) {
        set<ll> all_like = v_intersect(likes);
        printf("%lu\n", all_like.size());
    } else {
        set<ll> all_like = v_intersect(likes);
        set<ll> some_hate = v_union(hates);
        /*
        printf("LIKE :");
        for (ll x : all_like) {
            printf("%lld ", x);
        }
        printf("\n");

        printf("hte :");
        for (ll x : some_hate) {
            printf("%lld ", x);
        }
        printf("\n");
        */

        for (ll x : some_hate) {
            auto it = all_like.find(x);
            if (it != end(all_like)) {
                all_like.erase(it);
            }
        }

        printf("%lu\n", all_like.size());
    }
    
    return 0;
}
