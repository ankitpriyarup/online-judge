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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, t1, t2;
    scanf(" %d %d %d", &n, &t1, &t2);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(t1, 0);
    pq.emplace(t2, 1);

    int done = 0;
    int t;
    while (true) {
        t = pq.top().first;
        vector<int> ppl;
        while (!pq.empty() and pq.top().first == t) {
            ppl.push_back(pq.top().second);
            pq.pop();
        }
        done += ppl.size();
        if (done >= n) {
            break;
        }
        for (int x : ppl) {
            if (x == 0) {
                pq.emplace(t + t1, 0);
            } else {
                pq.emplace(t + t2, 1);
            }
        }
    }

    while (!pq.empty()) {
        ++done;
        t = pq.top().first;
        pq.pop();
    }

    printf("%d %d\n", done, t);

    return 0;
}
