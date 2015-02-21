#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

int T, N, R, K, X, Y;
int mines[1001][2];
int dsu[1001];
int dsu_rank[1001];
int counts[1001];

int find(int x) {
    if (dsu[x] == x) {
        return x;
    }
    return find(dsu[x]);
}

void dsu_union(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);

    if (x_root == y_root) return;

    if (dsu_rank[x_root] < dsu_rank[y_root]) {
        dsu[x_root] = y_root;
        counts[y_root] += counts[x_root];
        counts[x_root] = 0;
    } else if (dsu_rank[x_root] > dsu_rank[y_root]) {
        dsu[y_root] = x_root;
        counts[x_root] += counts[y_root];
        counts[y_root] = 0;
    } else {
        dsu[y_root] = x_root;
        counts[x_root] += counts[y_root];
        counts[y_root] = 0;
        dsu_rank[y_root]++;
    }
}

double dist(int i, int j) {
    double x = mines[i][0] - mines[j][0];
    double y = mines[i][1] - mines[j][1];
    return sqrt(x*x + y*y);
}

int main() {
    cin >> T;

    for (int case_num = 0; case_num < T; case_num++) {
        cin >> N >> R >> K;
        for (int i = 0; i < N; i++) {
            cin >> mines[i][0] >> mines[i][1];
            dsu[i] = i;
            counts[i] = 1;
            dsu_rank[i] = 0;
        }

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (dist(i, j) <= 1.0 * R) {
                    dsu_union(i, j);
                }
            }
        }

        sort(counts, counts + N);

        int total = 0;
        for (int i = N - 1; i > (N - 1) - K; i--) {
            total += counts[i];
        }

//        cout << "total: " << total << '\n';

        if (total >= N) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
