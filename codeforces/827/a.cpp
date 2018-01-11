#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 100005;
const int MAXL = 2000026;
int n;

string chunks[MAXN];
vector<int> pos[MAXN];
char out[MAXL];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int m, x;
    int str_len = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 0; i < n; ++i) {
        cin >> chunks[i];

        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> x;
            --x;
            pos[i].push_back(x);
            str_len = max(str_len, x + (int) chunks[i].size());

            pq.push({x, i});
        }
    }

    for (int i = 0; i < str_len; ++i) {
        out[i] = 'a';
    }
    int end = 0;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        int seg_start = cur.first;
        int seg_end = cur.first + chunks[cur.second].size();

        if (seg_end < end) continue;

        for (int i = end; i < seg_start; ++i) {
            out[i] = 'a';
            cout << out[i];
        }

        end = max(end, seg_start);
        for (int i = end; i < seg_end; ++i) {
            out[i] = chunks[cur.second][i - seg_start];
            cout << out[i];
        }

        end = max(end, seg_end);
    }

    cout << '\n';

    return 0;
}
