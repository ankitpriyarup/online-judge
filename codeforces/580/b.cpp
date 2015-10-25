#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
    vector<pair<int, int> > friends;
    int N, D;
    cin >> N >> D;
    int a, b;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        friends.push_back(make_pair(a, b));
    }

    int tail = 0;
    int i = 0;
    long long ans = 0LL;
    long long cur = 0LL;

    sort(friends.begin(), friends.end());
    for (auto it = friends.begin(); it != friends.end(); ++it, ++i) {
        //cout << tail << " " << i << " " << cur << '\n';
        cur += it->second;
        while (tail < i && it->first - friends[tail].first >= D) {
            cur -= friends[tail].second;
            ++tail;
        }
        //cout << tail << " " << i << " " << cur << '\n';

        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;
}
