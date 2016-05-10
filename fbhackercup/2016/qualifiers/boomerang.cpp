#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int N;
vector<pair<int, int> > points;

long long centered_at(int pos) {
    map<long long, int> segments;

    pair<int, int> center = points[pos];
    for (int i = 0; i < N; ++i) {
        if (i == pos) {
            continue;
        }

        long long x = center.first - points[i].first;
        long long y = center.second - points[i].second;

        segments[x * x + y * y]++;
    }

    long long ans = 0;

    for (auto it = segments.begin(); it != segments.end(); ++it) {
        long long v = it->second;
        if (v < 2) {
            continue;
        }

        ans += v * (v - 1) / 2;
    }

    return ans;
}

int main() {
    int T;
    cin >> T;
    int x, y;
    for (int case_num = 1; case_num <= T; ++case_num) {
        cin >> N;
        points.clear();

        for (int i = 0; i < N; ++i) {
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }

        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += centered_at(i);
        }

        cout << "Case #" << case_num << ": " << ans << '\n';
    }
    return 0;
}
