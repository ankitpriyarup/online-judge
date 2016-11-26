#include <iostream>
#include <complex>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#define P(x) cout << (#x) << ": " << x << '\n';

using namespace std;
typedef complex<double> pt;
const double EPS = 1e-6;
const double PI = M_PI;

struct segment {
    char type;
    pt start;
    pt end;

    segment(char type, pt start, pt end): type(type), start(start), end(end) {};
};

vector<segment> segments;
set<int> hit;

int P;
pt fromString(string s) {
    int commaPos = s.find(',');
    int first = stoi(s.substr(0, commaPos));
    int second = stoi(s.substr(commaPos + 1));

    return pt(first, second);
}

pair<pt, pt> readInput() {
    string a, b;
    cin >> a >> b;

    pt pos = fromString(a);
    pt dir = fromString(b);

    cin >> P;
    char type;
    for (int i = 0; i < P; ++i) {
        cin >> type >> a >> b;
        pt start = fromString(a);
        pt end = fromString(b);

        segments.push_back(segment(type, start, end));
    }

    return make_pair(pos, dir);
}

double fixAngle(double angle) {
    return angle < 0 ? angle + 2 * PI : angle;
}

// return the amount to add to angle1 to get angle2
double angleDist(double angle1, double angle2) {
    if (angle1 <= angle2) {
        return angle2 - angle1;
    } else {
        return 2 * PI - angle1 + angle2;
    }
}

double dist(pt pos, pt dir, segment seg) {
    pt shiftedStart = seg.start - pos;
    pt shiftedEnd = seg.end - pos;
    double startAngle = fixAngle(arg(shiftedStart));
    double endAngle = fixAngle(arg(shiftedEnd));
    double myAngle = fixAngle(arg(dir));

    P(startAngle);
    P(endAngle);
    P(myAngle);

    return -1.0;
}

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        segments.clear();
        hit.clear();
        pair<pt, pt> posdir = readInput();
        queue<pair<pt, pt> > q;
        q.push(posdir);

        while (!q.empty()) {
            pair<pt, pt> cur = q.front();
            q.pop();
            pt pos = cur.first;
            pt dir = cur.second;

            // Figure out what the first segment hit is
            double minDist = 1e18;
            int segIndex = -1;
            P(pos);
            P(dir);
            for (int i = 0; i < P; ++i) {
                segment seg = segments[i];
                P(seg.start);
                P(seg.end);
                double curDist = dist(pos, dir, seg);
                if (curDist > -EPS and curDist < minDist) {
                    minDist = curDist;
                    segIndex = i;
                }
            }
        }
    }

    return 0;
}
