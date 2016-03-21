#include <iostream>
#include <algorithm>
#include <vector>

#define MAXN 100005

using namespace std;

int N, K, P;
int uf[MAXN];
int uf_rank[MAXN];

int find(int x) {
    int ans = uf[x];
    while (ans != uf[ans])
        ans = uf[ans];
    uf[x] = ans;
    return ans;
}

void merge(int x, int y) {
    int xroot = find(x); 
    int yroot = find(y); 

    if (xroot == yroot)
        return;

    if (uf_rank[xroot] < uf_rank[yroot]) {
        uf[xroot] = yroot;
    } else if (uf_rank[xroot] > uf_rank[yroot]) {
        uf[yroot] = xroot;
    } else {
        uf[xroot] = yroot;
        uf_rank[yroot]++;
    }
}

int main() {
    cin >> N >> K >> P;
    vector<pair<int, int> > v;
    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        v.push_back(make_pair(x, i));
        uf[i] = i;
        uf_rank[i] = 1;
    }

    sort(v.begin(), v.end());
    for (int i = 1; i < N; ++i) {
        int a = v[i - 1].first;
        int b = v[i].first;
        if (b - a <= K) {
            merge(v[i - 1].second, v[i].second);
        }
    }

    for (int i = 0; i < P; ++i) {
        cin >> x >> y;
        --x;
        --y;
        if (find(x) == find(y)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
