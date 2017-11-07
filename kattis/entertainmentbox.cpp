#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    scanf("%d %d", &n, &k);

    int a, b;
    vector<pii> events;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        events.push_back({b, a});
    }

    sort(begin(events), end(events));

    multiset<int> endings;
    for (int i = 0; i < k; ++i) 
        endings.insert(0);


    int ans = 0;
    for (int i = 0; i < n; ++i) {
        tie(b, a) = events[i];
        auto it = endings.upper_bound(a);
        if (it != endings.begin()) {
            it = prev(it);
            endings.erase(it);
            endings.insert(b);
            ++ans;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
