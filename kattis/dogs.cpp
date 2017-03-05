#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <complex> 
using namespace std;

typedef complex<long double> pt;

int n, m;
vector<pt> walk1, walk2;
vector<long double> start1, start2;
set<long double> events;

const long double dot(const pt& a, const pt& b) {
    return real(conj(a) * b);
}

const pt find_pos(vector<pt>& walk, vector<long double>& start, long double time) {
    int lo = 0;
    int hi = walk.size() - 1;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (start[mid] > time) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    return walk[lo] + ((time - start[lo]) / (start[lo + 1] - start[lo])) * (walk[lo + 1] - walk[lo]);
}

int main() {
    scanf("%d", &n);

    int x, y;
    scanf("%d %d", &x, &y);
    walk1.push_back(pt(x, y));

    long double time = 0.0;
    start1.push_back(time);
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &x, &y);
        walk1.push_back(pt(x, y));

        time += abs(walk1[i - 1] - walk1[i]);
        events.insert(time);
        start1.push_back(time);
    }

    long double end = time;

    scanf("%d", &m);
    scanf("%d %d", &x, &y);
    walk2.push_back(pt(x, y));

    time = 0.0;
    start2.push_back(time);
    for (int i = 1; i < m; ++i) {
        scanf("%d %d", &x, &y);
        walk2.push_back(pt(x, y));

        time += abs(walk2[i - 1] - walk2[i]);
        events.insert(time);
        start2.push_back(time);
    }

    /*
    for (int i = 0; i < n; ++i) {
        printf("%.9f ", start1[i]);
    }
    printf("\n");

    for (int i = 0; i < m; ++i) {
        printf("%.9f ", start2[i]);
    }
    printf("\n");
    */

    end = min(end, time);

    long double ans = 1e9;
    long double start = 0;
    for (long double t : events) {
        if (start >= end) break;
        // calculate the vectors of the two dogs
        // Find the minimum distance between them

        // printf("%.9f %.9f\n", start, t);
        pt p1s = find_pos(walk1, start1, start);
        pt p2s = find_pos(walk2, start2, start);

        pt p1e = find_pos(walk1, start1, t);
        pt p2e = find_pos(walk2, start2, t);

        /*
        printf("P1S %.9f %.9f\n", p1s.real(), p1s.imag()); 
        printf("P1E %.9f %.9f\n", p1e.real(), p1e.imag()); 
        printf("P2S %.9f %.9f\n", p2s.real(), p2s.imag()); 
        printf("P2E %.9f %.9f\n", p2e.real(), p2e.imag()); 
        */

        pt v1 = p1e - p1s;
        pt v2 = p2e - p2s;

        pt delta_p = p2s - p1s;
        pt delta_v = v2 - v1;

        long double min_dist = min(abs(p1s - p2s), abs(p1e - p2e));
        long double denom = dot(delta_v, delta_v);
        if (denom >= 0.0) {
            long double t = -dot(delta_p, delta_v) / denom;
            if (0.0 <= t and t <= 1) {
                min_dist = min(min_dist, abs(delta_p + delta_v * t));
            }
        }

        ans = min(ans, min_dist);
        start = t;
    }

    printf("%.12Lf\n", ans);

    return 0;
}
