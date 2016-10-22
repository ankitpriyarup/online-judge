#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <utility>
#define MAXN 200005

using namespace std;

int N;
int a[MAXN];

long long sum_tree[4 * MAXN];
long long min_tree[4 * MAXN];
long long lazy[4 * MAXN];

void build_tree(int node, int l, int r) {
    if (l == r) {
        sum_tree[node] = a[l];
        min_tree[node] = a[l];
    } else {
        int lchild = (node << 1) + 1;
        int rchild = lchild + 1;
        int mid = (l + r) >> 1;

        build_tree(lchild, l, mid);
        build_tree(rchild, mid + 1, r);
        sum_tree[node] = sum_tree[lchild] + sum_tree[rchild];
        min_tree[node] = min(min_tree[lchild], min_tree[rchild]);
    }
}

void propagate(int node) {
    int lchild = (node << 1) + 1;
    int rchild = lchild + 1;
    
    lazy[lchild] += lazy[node];
    lazy[rchild] += lazy[node];
    lazy[node] = 0;
}

void fix(int node, int l, int r) {
    int lchild = (node << 1) + 1;
    int rchild = lchild + 1;

    int mid = (l + r) >> 1;

    sum_tree[node] = (sum_tree[lchild] + (mid - l + 1) * lazy[lchild]) + (sum_tree[rchild] + (r - mid) * lazy[rchild]);
    min_tree[node] = min(min_tree[lchild] + lazy[lchild], min_tree[rchild] + lazy[rchild]);
}

long long sum_query(int node, int l, int r, int ql, int qr) {
    if (ql == l and qr == r) {
        return sum_tree[node] + (r - l + 1LL) * lazy[node];
    }

    propagate(node);

    int lchild = (node << 1) + 1;
    int rchild = lchild + 1;
    int mid = (l + r) >> 1;

    long long ans = 0;
    if (mid >= ql) {
        ans += sum_query(lchild, l, mid, ql, min(mid, qr));
    }
    if (mid + 1 <= qr) {
        ans += sum_query(rchild, mid + 1, r, max(ql, mid + 1), qr);
    }

    fix(node, l, r);

    return ans;
}

long long min_query(int node, int l, int r, int ql, int qr) {
    if (ql == l and qr == r) {
        return min_tree[node] + lazy[node];
    }

    propagate(node);

    int lchild = (node << 1) + 1;
    int rchild = lchild + 1;
    int mid = (l + r) >> 1;

    long long ans = 0x3fffffff;
    if (mid >= ql) {
        ans = min(ans, min_query(lchild, l, mid, ql, min(mid, qr)));
    }
    if (mid + 1 <= qr) {
        ans = min(ans, min_query(rchild, mid + 1, r, max(ql, mid + 1), qr));
    }

    fix(node, l, r);

    return ans;
}

void update(int node, int l, int r, int ul, int ur, int v) {
    if (ul == l and ur == r) {
        lazy[node] += v;
        return;
    }

    propagate(node);
    int lchild = (node << 1) + 1;
    int rchild = lchild + 1;
    int mid = (l + r) >> 1;

    if (mid >= ul) {
        update(lchild, l, mid, ul, min(mid, ur), v);
    }

    if (mid + 1 <= ur) {
        update(rchild, mid + 1, r, max(mid + 1, ul), ur, v);
    }

    fix(node, l, r);
}

int main() {
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");
    int Q;
    fin >> N >> Q;
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
    }

    memset(lazy, 0, sizeof(lazy));
    build_tree(0, 0, N - 1);

    char op;
    int a, b, c;
    while (Q-- > 0) {
        fin >> op >> a >> b;
        --a; --b;

        if (op == 'S') {
            fout << sum_query(0, 0, N - 1, a, b) << '\n';
        } else if (op == 'P') {
            fin >> c;
            update(0, 0, N - 1, a, b, c);
        } else {
            fout << min_query(0, 0, N - 1, a, b) << '\n';
        }
    }

    return 0;
}
