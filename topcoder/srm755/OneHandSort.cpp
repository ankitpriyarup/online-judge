#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

class OneHandSort {
public:
    vector<int> sortShelf(vector<int> a) {
        int n = a.size();
        vi b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i]] = i;
        }

        vi ans;
        for (int i = 0; i < n; ++i) {
            if (a[i] == i) continue;
            // x - what's in i's spot?
            // y - where is i?
            int x = a[i];
            int y = b[i];
            ans.push_back(i);
            ans.push_back(y);
            ans.push_back(n);
            a[i] = i;
            a[y] = x;
            b[x] = y;
        }

        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    return 0;
}
