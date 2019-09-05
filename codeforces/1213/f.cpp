#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
using vi = vector<int>;

void toggle(set<int>& s, int x) {
    auto it = s.find(x);
    if (it == end(s)) {
        s.insert(x);
    } else {
        s.erase(it);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    vi p(n), q(n);
    for (auto& x : p) {
        cin >> x;
        --x;
    }
    for (auto& x : q) {
        cin >> x;
        --x;
    }

    set<int> s;
    vector<int> dx(n, 0);
    for (int i = 0; i < n; ++i) {
        toggle(s, p[i]);
        toggle(s, q[i]);
        if (s.empty()) {
            ++dx[i];
        }
    }

    string res(n, 'a');
    for (int i = 1; i < n; ++i) {
        res[i] = res[i - 1];
        if (dx[i - 1] and res[i] < 'z') {
            ++res[i];
        }
    }

    if (res.back() - res[0] + 1 >= k) {
        cout << "YES\n";
        string pr(n, 'a');
        for (int i = 0; i < n; ++i) {
            pr[p[i]] = res[i];
        }

        cout << pr << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
