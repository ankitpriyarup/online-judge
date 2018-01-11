#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;
int n;
int out[MAXN];

int main() {
    scanf("%d", &n);

    vector<pair<int, int> > a;
    vector<pair<int, int> > b;

    int x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        a.push_back({x, i});
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        b.push_back({x, i});
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
        int dest = b[i].second;
        out[dest] = a[i].first;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", out[i]);
    }

    return 0;
}
