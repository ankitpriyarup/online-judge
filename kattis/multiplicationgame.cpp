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

constexpr int MAXN = 47000;
int sieve[MAXN];
vector<int> primes;

void gen_sieve() {
    primes.push_back(2);
    for (int i = 2; i < MAXN; i += 2) {
        sieve[i] = 2;
    }

    for (int i = 3; i < MAXN; i += 2) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            primes.push_back(i);
            for (ll j = 1LL * i * i; j < MAXN; j += i)
                sieve[j] = i;
        }
    }
}

vector<int> factor(int n) {
    vector<int> res;
    for (int p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            res.push_back(0);
            while (n % p == 0) {
                ++res.back();
                n /= p;
            }
        }
    }

    if (n > 1) {
        res.push_back(1);
    }

    sort(begin(res), end(res));
    reverse(begin(res), end(res));
    return res;
}

struct state {
    bool extra;
    vector<int> moves;

    vector<state> follow() const {
        vector<state> res;
        for (int i = 0; i < moves.size(); ++i) {
            vector<int> v2(begin(moves), end(moves));
            --v2[i];
            int j = i;
            bool nextra = extra;
            while (j + 1 < moves.size() and v2[j] < v2[j + 1]) {
                swap(v2[j], v2[j + 1]);
                ++j;
            }
            if (v2.back() == 0) {
                v2.pop_back();
                nextra = true;
            }

            res.push_back({nextra, v2});
        }

        return res;
    }

    bool operator<(const state& other) const {
        return tie(extra, moves) < tie(other.extra, other.moves);
    }
};

map<state, int> memo;

int score(const state& s) {
    if (s.moves.empty()) {
        return 0;
    }

    if (memo.find(s) != end(memo))
        return memo[s];

    bool to_loss = false;
    bool to_tie = s.extra;

    for (const state& follow : s.follow()) {
        int val = score(follow);
        if (val == 2)
            to_tie = true;
        if (val == 0) {
            to_loss = true;
            break;
        }
    }

    if (to_loss) {
        return memo[s] = 1;
    } else if (to_tie) {
        return memo[s] = 2;
    } else {
        return memo[s] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    gen_sieve();

    int T;
    cin >> T;

    string start;
    int n;
    vector<string> names = {"Alice", "Bob"};
    while (T-- > 0) {
        cin >> n >> start;
        vector<int> v = factor(n);
        state cur = {false, v};

        int res = score(cur);

        if (res == 2) {
            cout << "tie" << '\n';
        } else if (res == 0) {
            for (string name : names)
                if (name != start)
                    cout << name << '\n';
        } else {
            cout << start << '\n';;
        }
    }

    return 0;
}
