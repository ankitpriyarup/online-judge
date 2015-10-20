#include <iostream>
#include <set>
#include <queue>
#include <map>

using namespace std;

int main() {
    int C;
    cin >> C;

    int N;

    while (C --> 0) {
        cin >> N;
        map<string, int> preq_count;
        multimap<string, string> preq_map;
        multimap<string, string> asdf;
        map<string, long long> scores;
        set<string> seen;
        queue<string> q;

        for (int i = 0; i < N; ++i) {
            string klass, p;
            int diff, preq;
            cin >> klass >> diff >> preq;
            preq_count.insert(make_pair(klass, preq));
            scores.insert(make_pair(klass, diff));
            if (preq == 0) {
                q.push(klass);
            }

            for (int j = 0; j < preq; ++j) {
                cin >> p;
                preq_map.insert(make_pair(p, klass));
                asdf.insert(make_pair(klass, p));
            }
        }

        string ans;
        long long max_score = 0;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (seen.find(cur) != seen.end()) {
                continue;
            }
            seen.insert(cur);

            auto jkl = asdf.equal_range(cur);
            for (auto it = jkl.first; it != jkl.second; it++) {
                scores[cur] += scores[it->second];
            }

            if (scores[cur] > max_score) {
                max_score = scores[cur];
                ans = cur;
            }

            auto ret = preq_map.equal_range(cur);
            for (auto it = ret.first; it != ret.second; it++) {
                preq_count[it->second]--;
                if (preq_count[it->second] <= 0) {
                    q.push(it->second);
                }
            }
        }

        cout << ans << " " << max_score << '\n';
    }
    return 0;
}
