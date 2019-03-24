#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll INF = 1e14;

/*
 * A treap is an implementation of a balanced binary search tree (BBST).
 *
 * Every node in the treap has a key and a random priority. The keys satisfy
 * the BST property and the priorities satisfy the heap property. (Max-heap on
 * priorities).
 *
 * Lot of implementation tricks taken from KACTL.
 */
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;

    int val, priority, size;
    // pref and suff can be empty but sum cannot
    ll sum, max_pref, max_suff, max_sum;
    bool has_range_set, is_reverse;

    // TODO: investigate different RNGs
    Node(int val): val(val), priority(rand()), size(1),
                   has_range_set(false), is_reverse(false) {
        sum = val;
        max_pref = max_suff = max(0, val);
        max_sum = val;
    }

    ~Node() {
        if (left != nullptr) {
            delete left;
        }
        if (right != nullptr) {
            delete right;
        }
    }

    // Push down lazy values
    void push();

    // Recompute aggregate stats like sizes. Need to call ANY TIME you update
    // any field.
    void pull();
};

int subtree_size(const Node* node) {
    return node == nullptr ? 0 : node->size;
}

ll subtree_sum(const Node* node) {
    return node == nullptr ? 0 : node->sum;
}

ll subtree_pref(const Node* node) {
    return node == nullptr ? 0 : node->max_pref;
}

ll subtree_suff(const Node* node) {
    return node == nullptr ? 0 : node->max_suff;
}

ll subtree_max_sum(const Node* node) {
    return node == nullptr ? -INF : node->max_sum;
}

void subtree_set(Node* node, int val) {
    if (node == nullptr)
        return;

    node->val = val;
    node->sum = 1LL * node->size * val;
    node->max_pref = node->max_suff = max(0LL, node->sum);
    node->max_sum = node->sum < 0 ? static_cast<ll>(node->val) : node->sum;

    node->has_range_set = true;
}

void subtree_reverse(Node* node) {
    if (node == nullptr)
        return;

    swap(node->max_pref, node->max_suff);
    node->is_reverse ^= 1;
}

void Node::push() {
    if (has_range_set) {
        subtree_set(left, val);
        subtree_set(right, val);

        has_range_set = false;
    }

    if (is_reverse) {
        subtree_reverse(left);
        subtree_reverse(right);
        swap(left, right);

        is_reverse = false;
    }
}

void Node::pull() {
    size = subtree_size(left) + subtree_size(right) + 1;
    sum = subtree_sum(left) + subtree_sum(right) + static_cast<ll>(val);

    max_pref = max(subtree_pref(left), subtree_sum(left) + val + subtree_pref(right));
    max_suff = max(subtree_suff(right), subtree_suff(left) + val + subtree_sum(right));

    ll from_children = max(subtree_max_sum(left), subtree_max_sum(right));
    ll with_self = subtree_suff(left) + val + subtree_pref(right);
    max_sum = max(from_children, with_self);
}

// Split into two subtrees, given size of left subtree.
pair<Node*, Node*> split_size(Node* node, int take) {
    assert(0 <= take and take <= subtree_size(node));
    if (take == 0) {
        return make_pair(nullptr, node);
    }

    assert(node != nullptr);
    node->push();
    int left_sz = subtree_size(node->left);
    if (take <= left_sz) {
        pair<Node*, Node*> left_split = split_size(node->left, take);
        node->left = left_split.second;
        node->pull();

        return make_pair(left_split.first, node);
    } else {
        pair<Node*, Node*> right_split = split_size(node->right, take - left_sz - 1);
        node->right = right_split.first;
        node->pull();
        return make_pair(node, right_split.second);
    }
}

// Merge two treaps, where all values in left <= all values in right.
Node* merge(Node* left, Node* right) {
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    left->push();
    right->push();
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        left->pull();

        return left;
    } else {
        right->left = merge(left, right->left);
        right->pull();

        return right;
    }
}

// start is 1 indexed. Split int 3 treaps, before [0, start), [start, start + len), [start + len, )
tuple<Node*, Node*, Node*> split3(Node* root, int start, int len) {
    --start;
    pair<Node*, Node*> split1 = split_size(root, start);
    pair<Node*, Node*> split2 = split_size(split1.second, len);

    return make_tuple(split1.first, split2.first, split2.second);
}

Node* merge3(Node* a, Node* b, Node* c) {
    Node* ab = merge(a, b);
    return merge(ab, c);
}

Node* build_treap(const vector<int>& a, int l, int r) {
    if (l >= r) {
        return nullptr;
    }
    if (l + 1 == r) {
        int x = a.at(l);
        return new Node(x);
    }
    int m = (l + r) >> 1;

    return merge(build_treap(a, l, m), build_treap(a, m, r));
}

Node* read_treap(int len) {
    vector<int> a(len);
    for (int i = 0; i < len; ++i) {
        scanf(" %d", &a[i]);
    }

    return build_treap(a, 0, len);
}

Node* make_same(Node* root, int start, int len, int val) {
    Node *a, *b, *c;
    tie(a, b, c) = split3(root, start, len);

    subtree_set(b, val);
    return merge3(a, b, c);
}

Node* insert(Node* root, int start, int len) {
    Node* new_treap = read_treap(len);

    Node *a, *b;
    tie(a, b) = split_size(root, start);

    return merge3(a, new_treap, b);
}

Node* remove(Node* root, int start, int len) {
    Node *a, *b, *c;
    tie(a, b, c) = split3(root, start, len);

    if (b != nullptr)
        delete b;

    return merge(a, c);
}

Node* reverse_range(Node* root, int start, int len) {
    Node *a, *b, *c;
    tie(a, b, c) = split3(root, start, len);

    subtree_reverse(b);

    return merge3(a, b, c);
}

pair<ll, Node*> get_sum(Node* root, int start, int len) {
    Node *a, *b, *c;
    tie(a, b, c) = split3(root, start, len);

    ll ans = subtree_sum(b);

    return {ans, merge3(a, b, c)};
}

int main() {
    int T = 1;
    // scanf(" %d", &T);

    char cmd[20];
    while (T-- > 0) {
        int n, m;
        scanf(" %d %d", &n, &m);
        Node* root = read_treap(n);

        int start, len, val;
        ll ans;
        while (m-- > 0) {
            scanf(" %s", cmd);
            if (!strcmp(cmd, "MAKE-SAME")) {
                scanf(" %d %d %d", &start, &len, &val);
                root = make_same(root, start, len, val);
            } else if (!strcmp(cmd, "INSERT")) {
                scanf(" %d %d", &start, &len);
                root = insert(root, start, len);
            } else if (!strcmp(cmd, "DELETE")) {
                scanf(" %d %d", &start, &len);
                root = remove(root, start, len);
            } else if (!strcmp(cmd, "REVERSE")) {
                scanf(" %d %d", &start, &len);
                root = reverse_range(root, start, len);
            } else if (!strcmp(cmd, "GET-SUM")) {
                scanf(" %d %d", &start, &len);
                tie(ans, root) = get_sum(root, start, len);
                printf("%lld\n", ans);
            } else if (!strcmp(cmd, "MAX-SUM")) {
                printf("%lld\n", subtree_max_sum(root));
            } else {
                printf("UNRECOGNIZED CMD: %s\n", cmd);
                assert(false);
            }
        }

        delete root;
    }

    return 0;
}
