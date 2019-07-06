#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct TwoSet {
    int right_sz;
    multiset<int> left, right;

    TwoSet(int n): right_sz(n) {}

    void balance() {
        while (!right.empty() and !left.empty() and *begin(right) < *prev(end(left))) {
            auto it = begin(right);
            left.insert(*it);
            right.erase(it);
        }

        while (!left.empty() and right.size() < right_sz) {
            auto it = prev(end(left));
            right.insert(*it);
            left.erase(it);
        }

        while (right.size() > right_sz) {
            auto it = begin(right);
            left.insert(*it);
            right.erase(it);
        }
    }

    void add(int x) {
        if (right.empty() or x > *begin(right)) {
            right.insert(x);
        } else {
            left.insert(x);
        }
    }

    void remove(int x) {
        if (!right.empty() and x >= *begin(right)) {
            auto it = right.find(x);
            right.erase(it);
        } else if (!left.empty()) {
            auto it = left.find(x);
            left.erase(it);
        } else {
            assert(false);
        }
    }

    int score() const {
        return *prev(end(left));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto& x : a) {
        cin >> x;
    }

    if (k == 1) {
        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
        return 0;
    }

    TwoSet ts(k / 2);
    for (int i = 0; i < k; ++i) {
        ts.add(a[i]);
    }
    ts.balance();

    cout << ts.score() << ' ';
    for (int i = k; i < n; ++i) {
        ts.remove(a[i - k]);
        ts.add(a[i]);
        ts.balance();

        cout << ts.score() << ' ';
    }
    cout << '\n';

    return 0;
}
