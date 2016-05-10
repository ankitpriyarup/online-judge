#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

long long L, N, M, D;
long long W[100004];

int main() {
    int T;
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cin >> L >> N >> M >> D;
        // first one is the time this op finishes, 
        // second is the machine
        priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;

        for (int i = 0; i < N; ++i) {
            cin >> W[i];
            pq.push(make_pair(W[i], i));
        }

        vector<long long> wash_times;
        while (!pq.empty() and (int)wash_times.size() < L) {
            pair<long long, int> cur = pq.top();
            pq.pop();

            long long time = cur.first;
            int machine = cur.second;

            wash_times.push_back(time);
            pq.push(make_pair(time + W[machine], machine));
        }
        /*
        for (auto it = wash_times.begin(); it != wash_times.end(); ++it) {
            cout << *it << " ";
        }
        cout << '\n';
        */

        long long ans;
        if (M >= L) {
            ans = wash_times[wash_times.size() - 1] + D;
        } else {
            priority_queue<long long, vector<long long>, greater<long long> > pq2;
            for (int i = 0; i < M; ++i) {
                pq2.push(0);
            }

            for (int i = 0; i < L; ++i) {
                long long time = pq2.top();
                pq2.pop();

                long long next = max(time, wash_times[i]) + D;
                pq2.push(next);
                ans = next;
            }
        }

        cout << "Case #" << case_num << ": " << ans << '\n';
    }
    return 0;
}
