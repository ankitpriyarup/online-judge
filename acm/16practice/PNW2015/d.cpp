#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> a;
    vector<int> b;

    int x;
    for (int i = 0; i < 3; ++i) {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < 3; ++i) {
        cin >> x;
        b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    bool works = (a == b) and (a[0] * a[0] + a[1] * a[1] == a[2] * a[2]);
    if (works) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
