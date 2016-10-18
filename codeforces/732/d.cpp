#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int n, m;
int d[100005];
int a[100005];
// last day, test
pair<int, int> last_chance[100005];

bool works(int test) {
    //cout << "works(" << test << ");\n";
    // can you pass everything in n days
    for (int i = 0; i < m; ++i) {
        last_chance[i] = make_pair(-1, i);
    }

    for (int i = 0; i < test; ++i) {
        if (d[i] >= 0)
            last_chance[d[i]] = make_pair(i, d[i]);
    }

    // process the last chances in order
    sort(last_chance, last_chance + m);
    if (last_chance[0].first == -1) {
        return false;
    }

    long long prep = 0;
    int last = -1;
    for (int i = 0; i < m; ++i) {
        prep += (last_chance[i].first - last - 1);
        //cout << last_chance[i].first << ' ' << last_chance[i].second << ' ' << prep << '\n';

        prep -= a[last_chance[i].second];
        last = last_chance[i].first;
        if (prep < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        --d[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    // binary search on number of days
    if (works(n)) {
        //cout << "-----\n";
        int lo = 0;
        int hi = n;
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (works(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
            //cout << "-----\n";
        }

        cout << hi << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}
