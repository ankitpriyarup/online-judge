#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int x, y;
    vector<pair<int, int> > times;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        times.push_back(make_pair(x, y));
    }

    sort(times.begin(), times.end());

    int last = -1;

    for (int i = 0; i < N; ++i) {
        // take the second time if possible
        if (times[i].second >= last) {
            last = times[i].second;
        } else {
            last = times[i].first;
        }
    }

    cout << last << '\n';

    return 0;
}
