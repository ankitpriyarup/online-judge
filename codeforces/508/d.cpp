#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXC = 65;

int n;
vector<pair<int, int> > graph[MAXC][MAXC];
int in_degree[MAXC][MAXC];
int out_degree[MAXC][MAXC];
bool visit[MAXC][MAXC];

int from_char(char c) {
    if ('a' <= c and c <= 'z')
        return c - 'a';
    else if ('A' <= c and c <= 'Z')
        return c - 'A' + 26;
    else
        return c - '0' + 26 + 26;
}

char to_char(int x) {
    if (x < 26)
        return x + 'a';
    else if (x < 52)
        return x + 'A' - 26;
    else
        return x + '0' - 26 - 26;
}

int my_abs(int x) {
    return (x < 0) ? -x : x;
}

vector<char> circuit;

void find_path(int a, int b) {
    // printf("Visiting %d %d\n", a, b);
    while (!graph[a][b].empty()) {
        pair<int, int> next_node = graph[a][b].back();
        graph[a][b].pop_back();

        find_path(next_node.first, next_node.second);
    }

    // circuit.push_back(to_char(a));
    circuit.push_back(to_char(b));
}

void dfs(int a, int b) {
    for (pair<int, int> next_node : graph[a][b]) {
        int x = next_node.first;
        int y = next_node.second;

        if (!visit[x][y]) {
            visit[x][y] = true;
            dfs(x, y);
        }
    }
}

char scrub[5];
int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", scrub);

        int a = from_char(scrub[0]);
        int b = from_char(scrub[1]);
        int c = from_char(scrub[2]);

        graph[a][b].push_back(make_pair(b, c));
        // printf("Creating edge from %d %d to %d %d\n", a, b, b, c);

        ++in_degree[b][c];
        ++out_degree[a][b];
    }

    int num_start = 0;
    int num_end = 0;
    int num_odd = 0;
    bool impossible = false;

    int startx = -1;
    int starty = -1;

    for (int i = 0; i < MAXC; ++i) {
        for (int j = 0; j < MAXC; ++j) {
            if (in_degree[i][j] + 1 == out_degree[i][j]) {
                startx = i;
                starty = j;
                ++num_start;
            } else if (out_degree[i][j] + 1 == in_degree[i][j]) {
                ++num_end;
            } else if ((in_degree[i][j] + out_degree[i][j]) % 2 == 1) {
                ++num_odd;
            }

            if (my_abs(in_degree[i][j] - out_degree[i][j]) > 1) {
                impossible = true;
            }

            if (startx == -1 and out_degree[i][j] > 0) {
                startx = i;
                starty = j;
            }
        }
    }

    visit[startx][starty] = true;
    dfs(startx, starty);
    for (int i = 0; !impossible and i < MAXC; ++i) {
        for (int j = 0; !impossible and j < MAXC; ++j) {
            if ((in_degree[i][j] > 0 or out_degree[i][j] > 0) and !visit[i][j]) {
                impossible = true;
            }
        }
    }

    // printf("%d %d %d\n", num_start, num_end, num_odd);
    if (impossible or num_start > 1 or num_end > 1 or num_odd > 0) {
        puts("NO");
    } else {
        find_path(startx, starty);
        circuit.push_back(to_char(startx));

        puts("YES");
        for (auto it = circuit.rbegin(); it != circuit.rend(); ++it) {
            printf("%c", *it);
        }
        puts("");
    }

    return 0;
}
