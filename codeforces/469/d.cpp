#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n), res(n, 0);
    map<int, int> m;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        m[v[i]] = i;
    }

    sort(begin(v), end(v));

    bool flip = a > b;
    if (flip)
        swap(a, b);

    if (a == b) {
        bool valid = true;
        for (int x : v) {
            valid &= m.count(a - x) > 0;
        }

        if (valid) {
            cout << "YES\n";
            for (int x : res)
                cout << x << " ";
        } else {
            cout << "NO\n";
        }

        return 0;
    }

    for (int x : v) {
        if (!m.count(x)) continue;
        bool hasA = m.count(a - x);
        bool hasB = m.count(b - x);
        if (hasB) {
            res[m[x]] = 1;
            res[m[b - x]] = 1;
            m.erase(x);
            m.erase(b - x);
        } else if (hasA) {
            m.erase(x);
            m.erase(a - x);
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int x : res)
        cout << (flip ^ x) << " ";


    return 0;
}
