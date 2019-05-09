#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

vi parse(const string& s) {
    vi freq(26, 0);
    int p = 0;
    while (p < s.size()) {
        int idx = s[p] - 'A';
        if (p + 1 == s.size() or s[p + 1] > '9') {
            ++freq[idx];
            ++p;
            continue;
        }

        int v = 0;
        while (p + 1 < s.size() and s[p + 1] <= '9') {
            v *= 10;
            v += s[p + 1] - '0';
            ++p;
        }
        ++p;

        freq[idx] += v;
    }

    return freq;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string src, sink;
    int k;
    cin >> src >> k >> sink;
    vi src_freq = parse(src);
    vi sink_freq = parse(sink);
    ll ans = 1e9 + 7;
    for (int i = 0; i < 26; ++i) {
        if (!sink_freq[i]) 
            continue;
        ans = min(ans, 1LL * k * src_freq[i] / sink_freq[i]);
    }

    cout << ans << '\n';

    return 0;
}
