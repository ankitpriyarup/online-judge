#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p, m;
    cin >> n >> p >> m;
    vector<string> names(n);
    for (auto& name : names) {
        cin >> name;
    }

    map<string, int> scores;
    set<string> won;
    while (m-- > 0) {
        string name;
        int points;
        cin >> name >> points;
        if (!won.count(name)) {
            scores[name] += points;
            if (scores[name] >= p) {
                won.insert(name);
                cout << name << ' ' << "wins!\n";
            }
        }
    }

    if (won.empty()) {
        cout << "No winner!\n";
    }
    
    return 0;
}
