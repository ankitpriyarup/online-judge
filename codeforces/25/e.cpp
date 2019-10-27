#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

vi Z(const string& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}

bool contains(const string& hay, const string& needle) {
    vi res = Z(needle + hay);
    for (int i = sz(needle); i < sz(res); ++i) {
        if (res[i] == sz(needle))
            return true;
    }

    return false;
}

int score(const string& a, const string& b) {
    // cout << "score" << a << ' ' << b << '\n';

    // find the longest prefix of B which is a suffix of A
    // Z function of B + A
    vi res = Z(b + a);
    /*
    for (int x : res) {
        cout << x << ' ';
    }
    cout << '\n';
    */

    int ans = 0;
    for (int i = 0; i < sz(a); ++i) {
        if (res[sz(b) + i] <= sz(b) and i + res[sz(b) + i] == sz(a)) {
            ans = res[sz(b) + i];
            break;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<string> words(3);
    for (int i = 0; i < 3; ++i) {
        cin >> words[i];
    }

    int ans = sz(words[0]) + sz(words[1]) + sz(words[2]);
    vi order(3);
    iota(all(order), 0);
    do {
        string tmp;
        if (contains(words[order[0]], words[order[1]])) {
            tmp = words[order[0]];
        } else {
            // cout << order[0] << ' ' << order[1] << ' ' << order[2] << '\n';
            // cout << t << ' ' << '\n';
            int t = score(words[order[0]], words[order[1]]);

            tmp = t == sz(words[order[1]]) ? words[order[0]] : words[order[0]] + words[order[1]].substr(t);
        }

        if (contains(tmp, words[order[2]])) {
            ans = min(ans, sz(tmp));
        } else {
            int u = score(tmp, words[order[2]]);
            // cout << u << ' ' << '\n';

            ans = min(ans, sz(tmp) + sz(words[order[2]]) - u);
        }
    } while (next_permutation(all(order)));

    cout << ans << '\n';

    return 0;
}
