#include <iostream>

using namespace std;

int find(int* dsu, int x) {
    if (x != dsu[x]) {
        int parent = find(dsu, dsu[x]);
        dsu[x] = parent;
        return dsu[x];
    } else {
        return x;
    }
}

void merge(int* dsu, int* rank, int* size, int x, int y) {
    int xroot = find(dsu, x);
    int yroot = find(dsu, y);

    if (xroot == yroot) {
        return;
    }

    if (rank[xroot] < rank[yroot]) {
        dsu[xroot] = yroot;
        size[yroot] += size[xroot];
        size[xroot] = 0;
    } else if (rank[xroot] > rank[yroot]) {
        dsu[yroot] = xroot;
        size[xroot] += size[yroot];
        size[yroot] = 0;
    } else {
        dsu[yroot] = xroot;
        rank[xroot] += 1;
        size[xroot] += yroot;
        size[yroot] = 0;
    }
}

void print_dsu(int* dsu, int* size, int N) {
    for (int i = 0; i < N; ++i) {
        cout << dsu[i] << " ";
    }
    cout << '\n';

    for (int i = 0; i < N; ++i) {
        cout << size[i] << " ";
    }
    cout << '\n';
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int dsu[N];
    int rank[N];
    int size[N];

    for (int i = 0; i < N; ++i) {
        dsu[i] = i;
        rank[i] = 0;
        size[i] = 1;
    }

    for (int i = 0; i + K <= N; ++i) {
        int start = i;
        int end = i + K - 1;
        while (start < end) {
            //cout << "merging " << start << " and " << end << '\n';
            merge(dsu, rank, size, start, end);

            start++;
            end--;
        }
    }

    //print_dsu(dsu, size, N);

    long long ans = 1LL;
    for (int i = 0; i < N; ++i) {
        if (size[i] > 0) {
            ans *= M;
            ans %= 1000000007;
        }
    }

    cout << ans << '\n';
    return 0;
}
