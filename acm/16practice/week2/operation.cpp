#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <complex>
#include <vector>

using namespace std;

typedef complex<double> pt;
typedef pair<pt, pt> sleigh;

const double EPS = 1e-6;
const double FACTOR = 1.0;

int N;
vector<sleigh> sleighs;

double dot(pt a, pt b) {
    return real(conj(a) * b);
}

double time_to(pt start, double speed, sleigh dest, double time) {
    pt v = dest.second;
    pt p = dest.first + (time * v) - start;

    double a = dot(v, v) - speed * speed;
    double b = 2 * dot(p, v);
    double c = dot(p, p);

    double disc = b * b - 4 * a * c;
    double root1 = (-b + sqrt(disc)) / (2 * a);
    double root2 = (-b - sqrt(disc)) / (2 * a);

    if (root1 < EPS) {
        root1 = 1e18;
    }

    if (root2 < EPS) {
        root2 = 1e18;
    }

    if (root1 + EPS >= 1e18 && root2 + EPS >= 1e18) {
        return 0;
    }

    return min(root1, root2);
}

double solve(pt start, double speed, int* perm) {
    pt cur = start;
    double time = 0.0;

    for (int i = 0; i < N; ++i) {
        sleigh dest = sleighs[perm[i]];
        time += time_to(cur, speed, dest, time);
        time += FACTOR;
        cur = dest.first + (dest.second * time);
    }

    return time + time_to(cur, speed, make_pair(start, 0), time);
}

int main() {
    int case_num = 1;

    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        sleighs.clear();
        int perm[10];
        for (int i = 0; i < N; ++i) {
            double x, y, vx, vy;
            cin >> x >> y >> vx >> vy;
            pt pos(x, y);
            pt vel(vx, vy);

            sleighs.push_back(make_pair(pos, vel / FACTOR));
            perm[i] = i;
        }

        double sx, sy, u;
        cin >> sx >> sy >> u;
        u /= FACTOR;
        pt start(sx, sy);

        double ans = 1e18;
        do {
            ans = min(ans, solve(start, u, perm));
        } while (next_permutation(perm, perm + N));


        long long s = ceil((3600.0 / FACTOR) * ans);
        long long hours = s / 3600;
        long long minutes = (s % 3600) / 60;
        long long seconds = s % 60;

        cout << "Case " << case_num << ": ";
        cout << hours << " hour(s) ";
        cout << minutes << " minute(s) ";
        cout << seconds << " second(s)\n";
        ++case_num;
    }
    return 0;
}
