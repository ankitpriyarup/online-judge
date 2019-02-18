#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct node {
    char c;
    node* left;
    node* right;
    node(char c): c(c), left(nullptr), right(nullptr) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    node* head = new node(' ');
    node* cur = head;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        char d = s[i];
        if (d == 'L') {
            if (cur->left != nullptr) {
                cur = cur->left;
            }
        } else if (d == 'R') {
            if (cur->right != nullptr) {
                cur = cur->right;
            }
        } else {
            node* v = new node(d);
            v->right = cur->right;
            if (v->right != nullptr) {
                v->right->left = v;
            }
            cur->right = v;
            v->left = cur;

            cur = v;
        }
    }

    cur = head->right;
    string t = "";
    while (cur != nullptr) {
        t += cur->c;
        cur = cur->right;
    }

    cout << t << '\n';
    return 0;
}
