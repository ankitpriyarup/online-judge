#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXV = 2750132;
int min_factor[MAXV];
int num_primes;
int kth[MAXV];

void precompute() {
    num_primes = 0;
    for (int i = 2; i < MAXV; ++i) {
        if (!min_factor[i]) {
            kth[i] = ++num_primes;

            for (int j = i; j < MAXV; j += i) {
                if (min_factor[j] == 0)
                    min_factor[j] = i;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    precompute();

    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        ms.insert(x);
    }

    vector<int> a;
    while (!ms.empty()) {
        int x = *prev(end(ms));
        ms.erase(prev(end(ms)));
        if (kth[x] > 0) {
            // prime
            int y = kth[x];
            a.push_back(y);
            ms.erase(ms.find(y));
        } else {
            // not prime
            a.push_back(x);
            ms.erase(ms.find(x / min_factor[x]));
        }
    }

    for (int x : a) {
        cout << x << ' ';
    }

    return 0;
}
