#include <cstdio>
#include <algorithm>

#define MAXN 100005

using namespace std;

int n, q;
int a[MAXN];
int tree[4 * MAXN];

const int INF = 1e9;

void build_tree(int node, int left, int right) {
  if (left == right) {
    tree[node] = a[left];
  } else {
    int mid = (left + right) >> 1;
    build_tree(2 * node + 1, left, mid);
    build_tree(2 * node + 2, mid + 1, right);

    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
  }
}

int query(int node, int left, int right, int ql, int qr) {
  if (left == ql and right == qr) {
    return tree[node];
  }

  int mid = (left + right) >> 1;
  int ans = INF;

  if (ql <= mid) {
    ans = min(ans, query(2 * node + 1, left, mid, ql, min(mid, qr)));
  }

  if (qr > mid) {
    ans = min(ans, query(2 * node + 2, mid + 1, right, max(ql, mid + 1), qr));
  }

  return ans;
}

int main() {
  int t;
  int l, r;
  scanf("%d", &t);
  for (int case_num = 1; case_num <= t; ++case_num) {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }

    build_tree(0, 0, n - 1);

    printf("Case %d:\n", case_num);
    while (q-- > 0) {
      scanf("%d %d", &l, &r);
      --l; --r;
      printf("%d\n", query(0, 0, n - 1, l, r));
    }
  }
}
