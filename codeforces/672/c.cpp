#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
long long ax, ay, bx, by, tx, ty;
long long px[100005];
long long py[100005];

double dist(long long x1, long long y1, long long x2, long long y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> px[i] >> py[i];
    }

    // assume you start at the trash can
    double trash_ans = 0;
    for (int i = 0; i < n; ++i) {
        trash_ans += 2 * dist(tx, ty, px[i], py[i]);
    }

    double ans = trash_ans - dist(tx, ty, px[0], py[0]) + dist(ax, ay, px[0], py[0]);

    // option 1: A goes and does all the work
    for (int i = 0; i < n; ++i) {
        double d = dist(ax, ay, px[i], py[i]);
        ans = min(ans, trash_ans - dist(tx, ty, px[i], py[i]) + d);
    }

    // option 2: B goes and does all the work
    for (int i = 0; i < n; ++i) {
        double d = dist(bx, by, px[i], py[i]);
        ans = min(ans, trash_ans - dist(tx, ty, px[i], py[i]) + d);
    }

    // option 3: they both do work
    int ai = 0;
    int ad = dist(tx, ty, px[0], py[0]) - dist(ax, ay, px[0], py[0]);
    for (int i = 1; i < n; ++i) {
        double d = dist(tx, ty, px[i], py[i]) - dist(ax, ay, px[i], py[i]);
        if (d > ad) {
            ai = i;
            ad = d;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == ai) continue;
        double d = dist(bx, by, px[i], py[i]);
        ans = min(ans, trash_ans + dist(ax, ay, px[ai], py[ai]) + d - dist(tx, ty, px[ai], py[ai]) - dist(tx, ty, px[i], py[i]));
    }

    int bi = 0;
    int bd = dist(tx, ty, px[0], py[0]) - dist(bx, by, px[0], py[0]);
    for (int i = 1; i < n; ++i) {
        double d = dist(tx, ty, px[i], py[i]) - dist(bx, by, px[i], py[i]);
        if (d > bd) {
            bi = i;
            bd = d;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == bi) continue;
        double d = dist(ax, ay, px[i], py[i]);
        ans = min(ans, trash_ans + dist(bx, by, px[bi], py[bi]) + d - dist(tx, ty, px[bi], py[bi]) - dist(tx, ty, px[i], py[i]));
    }


    cout << setprecision(15) << ans << '\n';
    return 0;
}
