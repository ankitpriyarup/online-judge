#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int N;
string s;
bool visited[202][202][202];

int main() {
    cin >> N;
    cin >> s;

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < N; ++i) {
        if (s[i] == 'R')
            a++;
        else if (s[i] == 'G')
            b++;
        else
            c++;
    }

    memset(visited, 0, sizeof(visited));

    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(a, make_pair(b, c)));
    visited[a][b][c] = true;

    bool blue = false, green = false, red = false;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        int r = top.first;
        int g = top.second.first;
        int b = top.second.second;

        if (r == 0 and g == 0) {
            blue = true;
            continue;
        } else if (r == 0 and b == 0) {
            green = true;
            continue;
        } else if (g == 0 and b == 0) {
            red = true;
            continue;
        }

        if (r > 0 and g > 0 and !visited[r - 1][g - 1][b + 1]) {
            q.push(make_pair(r - 1, make_pair(g - 1, b + 1)));
            visited[r - 1][g - 1][b + 1] = true;
        }

        if (r > 0 and b > 0 and !visited[r - 1][g + 1][b - 1]) {
            q.push(make_pair(r - 1, make_pair(g + 1, b - 1)));
            visited[r - 1][g + 1][b - 1] = true;
        }

        if (g > 0 and b > 0 and !visited[r + 1][g - 1][b - 1]) {
            q.push(make_pair(r + 1, make_pair(g - 1, b - 1)));
            visited[r + 1][g - 1][b - 1] = true;
        }

        if (r > 1 and !visited[r - 1][g][b]) {
            q.push(make_pair(r - 1, make_pair(g, b)));
            visited[r - 1][g][b] = true;
        }
        if (g > 1 and !visited[r][g - 1][b]) {
            q.push(make_pair(r, make_pair(g - 1, b)));
            visited[r][g - 1][b] = true;
        }
        if (b > 1 and !visited[r][g][b - 1]) {
            q.push(make_pair(r, make_pair(g, b - 1)));
            visited[r][g][b - 1] = true;
        }
    }

    if (blue)
        cout << "B";
    if (green)
        cout << "G";
    if (red)
        cout << "R";

    cout << '\n';

    return 0;
}
