#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 1e7 + 1;
int comp[MAXN];
int num_primes = 0;
int primes[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    comp[0] = comp[1] = true;
    for (int i = 2; i < MAXN; ++i) {
        if (!comp[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                comp[j] = true;
            }
        }
    }

    int k;
    string s;
    while (cin >> k >> s) {
        int n = s.size();
        bool valid = true;
        for (int i = 0; valid and i < n; i += k) {
            int res = 0;
            for (int j = i; j < i + k; ++j) {
                res *= 10;
                res += s[j] - '0';
            }

            valid &= !comp[res];
        }

        cout << (valid ? ":)" : ":(") << '\n';
    }

    return 0;
}
