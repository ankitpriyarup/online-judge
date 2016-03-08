#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>

#define PI 3.14159265358979323846
#define EPS 1e-6

using namespace std;

int main() {
    int N, x, y;
    cin >> N;

    pair<long double, int> angles[100005];

    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        long double angle = atan2(y, x);
        if (angle < EPS) {
            angle += 2 * PI;
        }
        angles[i] = make_pair(angle, i + 1);
    }

    sort(angles, angles + N);
    int ans = 0;
    long double dist = abs(angles[N - 1].first - angles[0].first);
    if (dist > PI - EPS) {
        dist = 2 * PI - dist;
    }

    /*
    for (int i = 0; i < N; ++i) {
        cout << angles[i].first << ' ' << angles[i].second << '\n';
    }
    */

    //cout << "Distance between " << angles[N - 1].second << " and " << angles[(0)].second << " is " << dist << '\n';
    for (int i = 1; i < N; ++i) {
        long double d = abs(angles[i].first - angles[i - 1].first);
        if (d > PI - EPS) {
            d = 2 * PI - d;
        }

        //cout << "Distance between " << angles[i].second << " and " << angles[(i - 1)].second << " is " << d << '\n';
        if (d < dist) {
            ans = i;
            dist = d;
        }
    }

    if (ans == 0) {
        cout << angles[0].second << ' ' << angles[N - 1].second << '\n';
    } else {
        cout << angles[ans].second << ' ' << angles[ans - 1].second << '\n';
    }
}
