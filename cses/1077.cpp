#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

struct TwoSet {
    int left_sz;
    multiset<int> left, right;
    ll left_sum, right_sum;

    TwoSet(int n): left_sz(n), left_sum(0), right_sum(0) {}

    void balance() {
        while (!right.empty() and !left.empty() and *begin(right) < *prev(end(left))) {
            auto it = begin(right);

            left_sum += *it;
            right_sum -= *it;

            left.insert(*it);
            right.erase(it);
        }

        while (left.size() > left_sz) {
            auto it = prev(end(left));

            right_sum += *it;
            left_sum -= *it;

            right.insert(*it);
            left.erase(it);
        }

        while (!right.empty() and left.size() < left_sz) {
            auto it = begin(right);

            left_sum += *it;
            right_sum -= *it;

            left.insert(*it);
            right.erase(it);
        }
    }

    void add(int x) {
        if (right.empty() or x > *begin(right)) {
            right_sum += x;
            right.insert(x);
        } else {
            left_sum += x;
            left.insert(x);
        }
    }

    void remove(int x) {
        if (!right.empty() and x >= *begin(right)) {
            auto it = right.find(x);
            right_sum -= *it;
            right.erase(it);
        } else if (!left.empty()) {
            auto it = left.find(x);
            left_sum -= *it;
            left.erase(it);
        } else {
            assert(false);
        }
    }

    ll score() const {
        int med = *prev(end(left));
        return (1LL * left.size() * med - left_sum)
            + (right_sum - 1LL * right.size() * med);
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

    TwoSet ts((k + 1) / 2);
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
