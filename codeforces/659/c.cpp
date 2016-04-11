#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int n, m;
int owned[100005];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> owned[i];
    }

    sort(owned, owned + n);
    int optr = 0;
    vector<int> ans;
    for (int i = 1; m > 0 && i <= m; ++i) {
        if (optr < n and owned[optr] == i) {
            optr++;
            continue;
        }
        m -= i;
        ans.push_back(i);
    }

    int k = ans.size();
    cout << k << '\n';
    if (k > 0) {
        cout << ans[0];
    }
    for (int i = 1; i < k; ++i) {
        cout << ' ' << ans[i];
    }
    cout << '\n';

    return 0;
}
