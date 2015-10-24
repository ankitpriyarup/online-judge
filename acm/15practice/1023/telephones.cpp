#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 || M == 0) {
            break;
        }

        vector<pair<int, int> > calls;
        int source, dest, start, dur;
        for (int i = 0; i < N; ++i) {
            cin >> source >> dest >> start >> dur;
            calls.push_back(make_pair(start, dur));
        }

        for (int i = 0; i < M; ++i) {
            cin >> start >> dur;
            int end = start + dur;
            int ans = 0;
            for (auto it = calls.begin(); it != calls.end(); ++it) {
                int call_start = it->first;
                int call_end = call_start + it->second;
                if (start < call_end && call_start < end) {
                    ans += 1;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
