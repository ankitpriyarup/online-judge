#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 102;
string names[MAXN];
int hp[MAXN], atk[MAXN], def[MAXN];
bool beats[MAXN][MAXN];

bool win(int x, int y) {
    int hp0 = hp[x];
    int hp1 = hp[y];

    int dmg0 = max(0, atk[y] - def[x]);
    int dmg1 = max(0, atk[x] - def[y]);
    if (dmg0 == 0 and dmg1 == 0) {
        return false;
    }

    while (hp0 > 0 and hp1 > 0) {
        hp0 -= dmg0;
        hp1 -= dmg1;
    }

    return hp0 > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> names[i] >> hp[i] >> atk[i] >> def[i];

        for (int j = 0; j < i; ++j) {
            beats[i][j] = win(i, j);
            beats[j][i] = win(j, i);
        }
    }

    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if ((beats[i][j] and beats[j][k] and beats[k][i]) 
                or  (beats[i][k] and beats[k][j] and beats[j][i])) {
                    ans.emplace_back(i, j, k);
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto& tup : ans) {
        int i, j, k;
        tie(i, j, k) = tup;
        cout << names[i] << ' ' << names[j] << ' ' << names[k] << '\n';
    }
    
    return 0;
}
