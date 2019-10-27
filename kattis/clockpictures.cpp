#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

template <typename T>
int min_rotation(const vector<T>& v) {
    int a = 0;
    int n = v.size();
    for (int b = 0; b < n; ++b) {
        for (int i = 0; i < n; ++i) {
            if (a + i == b or v[(a + i) % n] < v[(b + i) % n]) {
                b += max(0, i - 1);
                break;
            }

            if (v[(a + i) % n] > v[(b + i) % n]) {
                a = b;
                break;
            }
        }
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vi> diffs(2);
    for (int k = 0; k < 2; ++k) {
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(all(a));
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            diffs[k].push_back((a[j] - a[i] + 360000) % 360000);
        }

        rotate(begin(diffs[k]), begin(diffs[k]) + min_rotation(diffs[k]), end(diffs[k]));
    }

    if (diffs[0] == diffs[1]) {
        cout << "possible\n";
    } else {
        cout << "impossible\n";
    }
    
    return 0;
}
