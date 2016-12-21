#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int num_segments;

struct line {
    int slot;
    int start;
    int end;

    line(int slot, int start, int end): slot(slot), start(start), end(end) {}
};

vector<line> horizontals;
vector<line> verticals;

bool adjacent[255][255];
bool visited[255];
int pred[255];

bool intersect(int horizontal_index, int vertical_index) {
    line horizontal = horizontals[horizontal_index];
    line vertical = verticals[vertical_index];

    return horizontal.start <= vertical.slot and vertical.slot <= horizontal.end
       and vertical.start <= horizontal.slot and horizontal.slot <= vertical.end;
}

bool bfs(int source, int sink) {
    queue<int> q;
    q.push(source);

    memset(visited, 0, sizeof(visited));
    memset(pred, -1, sizeof(pred));
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i <= sink; ++i) {
            if (!visited[i] and adjacent[cur][i]) {
                q.push(i);
                visited[i] = true;
                pred[i] = cur;
            }
        }
    }

    return pred[sink] != -1;
}

int flow(int source, int sink) {
    int cost = 0;

    while (bfs(source, sink)) {
        int node = sink;
        while (node != source) {
            int p = pred[node];
            adjacent[p][node] = false;
            adjacent[node][p] = true;

            node = p;
        }

        ++cost;
    }

    return cost;
}

int main() {
    freopen("steeple.in", "r", stdin);
    freopen("steeple.out", "w", stdout);

    cin >> num_segments;

    int x1, y1, x2, y2;
    for (int i = 0; i < num_segments; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 == x2) {
            int start = min(y1, y2);
            int end = max(y1, y2);
            verticals.push_back(line(x1, start, end));
        } else {
            int start = min(x1, x2);
            int end = max(x1, x2);
            horizontals.push_back(line(y1, start, end));
        }
    }

    int num_horizontal = horizontals.size();
    int num_vertical = verticals.size();

    // Give the horizontals labels 0-|H| - 1, verticals get labels |H| to N - 1.
    memset(adjacent, false, sizeof(adjacent));
    for (int i = 0; i < num_horizontal; ++i) {
        for (int j = 0; j < num_vertical; ++j) {
            if (intersect(i, j)) {
                adjacent[i][j + num_horizontal] = true;
            }
        }
    }

    int source = num_segments;
    int sink = source + 1;
    for (int i = 0; i < num_horizontal; ++i) {
        adjacent[source][i] = true;
    }

    for (int i = 0; i < num_vertical; ++i) {
        adjacent[i + num_horizontal][sink] = true;
    }

    int max_matching = flow(source, sink);

    cout << (num_segments - max_matching) << '\n';

    return 0;
}
