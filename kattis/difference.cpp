#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <numeric>
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

// 0 1 3 7 12 20 30 44
// len of list to first appearances
// 0: 0
// 1: 1
// 2: 2 3 
// 3: 4 6 7
// 4: 5 9 11 12
// 5: 8 13 17 19 20
// 6: 10 18 23 27 29 30
// 7: 14 24 32 37 41 43 44
//
// Say d is the first element of V(i). Then V(i) = {v + d for v in v(i - 1)}
// Not related to triangle numbers

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a1, m; 
    cin >> a1 >> m;
    if (a1 == m) {
        cout << 1;
        return 0;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(a1);
    vector<int> old = {a1};
    int d = 1;
    int dist = 2;
    while (true) {
        while (!pq.empty() and pq.top() < d) {
            pq.pop();
        }
        while (!pq.empty() and pq.top() == d) {
            while (!pq.empty() and pq.top() == d)
                pq.pop();

            ++d;
        }

        // printf("D: %d\n", d);
        vector<int> new_vals = {d};
        if (d == m) {
            cout << dist << '\n';
            return 0;
        }
        for (int x : old) {
            new_vals.push_back(x + d);
            pq.push(x + d);

            if (new_vals.back() == m) {
                cout << dist << '\n';
                return 0;
            }
        }

        ++d;
        swap(old, new_vals);
        ++dist;
    }
    
    return 0;
}
