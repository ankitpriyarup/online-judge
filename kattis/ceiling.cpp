#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <complex>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct Tree {
    int x;
    Tree* left, * right;
    Tree(int x): x(x), left(nullptr), right(nullptr) {}
    ~Tree() {
        if (left != nullptr)
            delete left;
        if (right != nullptr)
            delete right;
    }

    void insert(int y) {
        if (y < x) {
            if (left == nullptr) {
                left = new Tree(y);
            } else {
                left->insert(y);
            }
        } else {
            if (right == nullptr) {
                right = new Tree(y);
            } else {
                right->insert(y);
            }
        }
    }
};

bool eq(Tree* a, Tree* b) {
    if (a == nullptr and b == nullptr)
        return true;
    if (a == nullptr or b == nullptr)
        return false;
    return eq(a->left, b->left) and eq(a->right, b->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    int x;
    scanf("%d %d", &n, &k);
    vector<Tree*> seen;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        Tree* root = new Tree(x);
        for (int j = 1; j < k; ++j) {
            scanf("%d", &x);
            root->insert(x);
        }

        bool first = true;
        for (Tree* t : seen) {
            first &= !eq(t, root);
        }

        if (first) {
            seen.push_back(root);
        } else {
            delete root;
        }
    }

    printf("%lu\n", seen.size());

    return 0;
}
