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

constexpr int MOD = 1000000007;

ll H(ll previous_hash, string &transaction, ll token) {
    ll v = previous_hash;
    for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31 + transaction[i]) % 1000000007;
    }
    return (v * 7 + token) % 1000000007;
}

ll get_token(ll previous_hash, string &transaction) {
    ll v = previous_hash;
    for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31LL + transaction[i]) % MOD;
    }

    return (10000000 - v * 7LL % MOD + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    string alice = "alice";
    string bob = "bob";

    ll tok_1 = get_token(n, alice);
    ll h1 = H(n, alice, tok_1);
    ll tok_2 = get_token(h1, bob);
    ll h2 = H(h1, bob, tok_2);
    
    cout << alice << ' ' << tok_1 << '\n';
    cout << bob << ' ' << tok_2 << '\n';

    // cout << n << ' ' << h1 << ' ' << h2 << '\n';
    return 0;
}
