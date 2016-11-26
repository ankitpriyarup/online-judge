#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int n;
vector<int> tree[1000060];
int pre_order[1000060];
int reverse_pre_order[1000060];

int salaries[1000060];
int size[1000060];

int lazy[4001000];
int min_seg_tree[4001000];
int max_seg_tree[4001000];
int p;

// do a pre order traversal
void traverse(int node) {
    pre_order[p] = node;
    reverse_pre_order[node] = p;
    size[node] = 1;
    ++p;

    for (int child : tree[node]) {
        traverse(child);
        size[node] += size[child];
    }
}

void build_tree(int node, int left, int right) {
    if (left == right) {
        min_seg_tree[node] = salaries[pre_order[left]];
        max_seg_tree[node] = salaries[pre_order[left]];
    } else {
        int mid = (left + right) >> 1;
        int lchild = node << 1;
        int rchild = lchild + 1;

        build_tree(lchild, left, mid);
        build_tree(rchild, mid + 1, right);

        min_seg_tree[node] = min(min_seg_tree[lchild], min_seg_tree[rchild]);
        max_seg_tree[node] = max(max_seg_tree[lchild], max_seg_tree[rchild]);
    }
}

void propagate(int node) {
    int lchild = node << 1;
    int rchild = lchild + 1;
    lazy[lchild] += lazy[node];
    lazy[rchild] += lazy[node];

    lazy[node] = 0;
}

void fix(int node) {
    int lchild = node << 1;
    int rchild = lchild + 1;
    min_seg_tree[node] = min(min_seg_tree[lchild] + lazy[lchild], min_seg_tree[rchild] + lazy[rchild]);
    max_seg_tree[node] = max(max_seg_tree[lchild] + lazy[lchild], max_seg_tree[rchild] + lazy[rchild]);
}

int min_query(int node, int l, int r, int ql, int qr) {
    if (l == ql and r == qr) {
        return min_seg_tree[node] + lazy[node];
    }

    int mid = (l + r) >> 1;
    int lchild = node << 1;
    int rchild = lchild + 1;

    propagate(node);
    int ans = INF;
    if (ql <= mid) {
        ans = min(ans, min_query(lchild, l, mid, ql, min(mid, qr)));
    }

    if (mid + 1 <= qr) {
        ans = min(ans, min_query(rchild, mid + 1, r, max(ql, mid + 1), qr));
    }
    fix(node);

    return ans;
}

int max_query(int node, int l, int r, int ql, int qr) {
    if (l == ql and r == qr) {
        return max_seg_tree[node] + lazy[node];
    }

    int mid = (l + r) >> 1;
    int lchild = node << 1;
    int rchild = lchild + 1;

    propagate(node);

    int ans = 0;
    if (ql <= mid) {
        ans = max(ans, max_query(lchild, l, mid, ql, min(mid, qr)));
    }

    if (mid + 1 <= qr) {
        ans = max(ans, max_query(rchild, mid + 1, r, max(ql, mid + 1), qr));
    }
    fix(node);

    return ans;
}

void update(int node, int l, int r, int ul, int ur, int v) {
    //printf("%d %d %d %d %d %d\n", node, l, r, ul, ur, v);
    if (l == ul and r == ur) {
        lazy[node] += v;
    } else {
        int mid = (l + r) >> 1;
        int lchild = node << 1;
        int rchild = lchild + 1;

        propagate(node);
        if (ul <= mid) {
            update(lchild, l, mid, ul, min(mid, ur), v);
        }
        if (mid + 1 <= ur) {
            update(rchild, mid + 1, r, max(ul, mid + 1), ur, v);
        }
        fix(node);
    }
}

int query(int l, int r) {
    int a = max_query(1, 1, n, l, r);
    int b = min_query(1, 1, n, l, r);
    return a - b;
}

void update(int l, int r, int v) {
    update(1, 1, n, l, r, v);
}

void print_tree(int tabs, int node) {
    if (node >= 10) return;

    for (int i = 0; i < tabs; ++i) {
        cout << '\t';
    }

    cout << min_seg_tree[node] << " | " << max_seg_tree[node] << "(" << lazy[node] << ")" << '\n';
    print_tree(tabs + 1, node * 2);
    print_tree(tabs + 1, node * 2 + 1);
}

void print_tree() {
    print_tree(0, 1);
}

int main() {
    int T, Q, supervisor, emp, value;
    char type;
    cin >> T;

    while (T-- > 0) {
        cin >> n;
        for (int i = 0; i <= n; ++i)
            tree[i].clear();

        for (int i = 2; i <= n; ++i) {
            cin >> supervisor;
            tree[supervisor].push_back(i);
        }

        for (int i = 1; i <= n; ++i) {
            cin >> salaries[i];
        }

        p = 1;
        memset(size, 0, sizeof(size));
        traverse(1);

        memset(lazy, 0, sizeof(lazy));
        build_tree(1, 1, n);

        cin >> Q;
        while (Q-- > 0) {
            cin >> type >> emp;
            if (type == 'Q') {
                cout << query(reverse_pre_order[emp], reverse_pre_order[emp] + size[emp] - 1) << '\n';
            } else {
                cin >> value;
                update(reverse_pre_order[emp], reverse_pre_order[emp] + size[emp] - 1, value);

            }

            //print_tree();
        }
    }

    return 0;
}
