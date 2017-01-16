#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <complex>

using namespace std;

typedef complex<double> pt;
pt freckles[1003];
bool visit[1003];

double dist(pt a, pt b) {
    return abs(a - b);
}

int main() {
    int num_cases, num_freckles;

    cin >> num_cases;
    while (num_cases-- > 0) {
        cin >> num_freckles;

        double x, y;
        for (int i = 0; i < num_freckles; ++i) {
            cin >> x >> y;
            freckles[i] = pt(x, y);
        }

        priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > pq;

        memset(visit, false, sizeof(visit));
        pq.push(make_pair(0.0, 0));

        double ans = 0.0;
        while (!pq.empty()) {
            pair<double, int> state = pq.top();
            pq.pop();

            double weight = state.first;
            int loc = state.second;

            if (visit[loc]) {
                continue;
            }

            visit[loc] = true;
            ans += weight;

            for (int i = 0; i < num_freckles; ++i) {
                if (!visit[i]) {
                    pq.push(make_pair(dist(freckles[loc], freckles[i]), i));
                }
            }
        }

        cout << fixed << setprecision(2) << ans << '\n';
    }
    return 0;
}
