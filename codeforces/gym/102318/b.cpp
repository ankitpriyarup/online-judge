#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

string grid[] = {"abcdefghi", "jklmnopqr", "stuvwxyz"};
int pos[26][2];

bool close(char a, char b) {
    a -= 'a';
    b -= 'a';
    int dx = abs(pos[a][0] - pos[b][0]);
    int dy = abs(pos[a][1] - pos[b][1]);
    return max(dx, dy) <= 1;
}

bool sim(const string& s, const string& t) {
    if (s.size() != t.size())
        return false;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (!close(s[i], t[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            int idx = grid[i][j] - 'a';
            pos[idx][0] = i;
            pos[idx][1] = j;
        }
    }

    int T;
    cin >> T;
    while (T-- > 0) {
        string a, b;
        cin >> a >> b;
        if (a == b) {
            cout << "1\n";
        } else if (sim(a, b)) {
            cout << "2\n";
        } else {
            cout << "3\n";
        }
    }
    
    return 0;
}
