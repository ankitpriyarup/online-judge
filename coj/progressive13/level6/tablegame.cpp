#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 10004;
int money[MAXN], links[MAXN][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, d;
    while (cin >> n >> d) {
        for (int i = 0; i < n; ++i) {
            money[i] = d;
            links[i][0]= i - 1;
            links[i][1] = i + 1;
        }
        links[0][0] = n - 1;
        links[n - 1][1] = 0;

        auto rem = [](int x) {
            links[links[x][0]][1] = links[x][1];
            links[links[x][1]][0] = links[x][0];
        };

        vector<tuple<bool, int, int>> moves;
        for (int i = 0; i < n - 1; ++i) {
            char m;
            int r, a;
            cin >> m >> r >> a;
            bool k = m == 'C';

            moves.emplace_back(k, r, a);
        }

        vector<pii> saved;
        int p = 0;
        for (int move = 0; links[p][0] != p; ++move) {
            bool k;
            int r, a;
            tie(k, r, a) = moves[move];

            // cout << "Starting move at " << (p + 1) << '\n';
            while (r-- > 0) {
                p = links[p][k];
            }

            // cout << "Moved to " << (p + 1) << '\n';

            money[p] += a;
            if (money[p] % 2 == 0) {
                int b = links[p][0];
                int c = links[p][1];
                // cout << "Delet " << (b + 1) << " " << (c + 1) << '\n';
                rem(b);
                rem(c);
            } else {
                // cout << "Save " << (p + 1) << " " << money[p] << '\n';
                saved.emplace_back(p, money[p]);

                int q = links[p][k];
                rem(p);

                p = q;
            }
        }
        saved.emplace_back(p, money[p]);

        sort(all(saved));
        for (auto& person : saved) {
            cout << (person.first + 1) << ' ' << person.second << '\n';
        }
    }
    
    return 0;
}
