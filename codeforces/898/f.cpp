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

template <ll M>
struct HashInterval {
	vector<ll> ha, pw;
	HashInterval(string& str) : ha(str.size() + 1), pw(ha) {
		pw[0] = 1;
		for (int i = 0; i < str.size(); ++i) {
			ha[i + 1] = ha[i] * 10LL + (str[i] - '0');
			pw[i + 1] = pw[i] * 10LL;
            ha[i + 1] %= M;
            pw[i + 1] %= M;
        }
	}

	ll hashInterval(int a, int b) { // hash [a, b)
		return (ha[b] + 2LL * M - (ha[a] * pw[b - a] % M)) % M;
	}

    bool test(int a, int b, int c) {
        ll h1 = hashInterval(0, a);
        ll h2 = hashInterval(a, a + b);
        ll h3 = hashInterval(a + b, a + b + c);

        return (h1 + h2) % M == h3;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    constexpr ll M1 = 1000000241;
    constexpr ll M2 = 1000000411;
    pair<HashInterval<M1>, HashInterval<M2>> hashes = {HashInterval<M1>(s), HashInterval<M2>(s)};
    for (int a = 1; a <= n; ++a) {
        // c is close to either a or b
        for (int c = a; c <= a + 1; ++c) {
            int b = n - a - c;
            if (b <= 0 or (b > 1 and s[a] == '0')) continue;
            if (c > 1 and s[a + b] == '0') continue;

            if (hashes.first.test(a, b, c) and hashes.second.test(a, b, c)) {
                cout << s.substr(0, a) << "+" << s.substr(a, b) << "=" << s.substr(a + b, c); 
                exit(0);
            }
        }
    }

    for (int b = 1; b <= n; ++b) {
        for (int c = b; c <= b + 1; ++c) {
            int a = n - b - c;
            if (a <= 0) continue;
            if (b > 1 and s[a] == '0') continue;
            if (c > 1 and s[a + b] == '0') continue;

            if (hashes.first.test(a, b, c) and hashes.second.test(a, b, c)) {
                cout << s.substr(0, a) << "+" << s.substr(a, b) << "=" << s.substr(a + b, c); 
                exit(0);
            }
        }
    }

    return 0;
}
