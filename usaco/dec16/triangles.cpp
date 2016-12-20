/**
 * Brute force, runs in O(N^4). Too slow
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef pair<int, int> pt;

int n;
vector<pt> points;

int out[303];

// Barycentric coordinate idea taken from:
// Taken from http://blackpawn.com/texts/pointinpoly/
long double dot(pt a, pt b) {
    return 1LL * a.first * b.first + 1LL * a.second * b.second;
}

bool within(pt a, pt b, pt c, pt x) {
    pt v0 = make_pair(c.first - a.first, c.second - a.second);
    pt v1 = make_pair(b.first - a.first, b.second - a.second);
    pt v2 = make_pair(x.first - a.first, x.second - a.second);

    long double dot00 = dot(v0, v0);
    long double dot01 = dot(v0, v1);
    long double dot02 = dot(v0, v2);
    long double dot11 = dot(v1, v1);
    long double dot12 = dot(v1, v2);

    long double denom = 1.0L / (dot00 * dot11 - dot01 * dot01);
    long double u = (dot11 * dot02 - dot01 * dot12) * denom;
    long double v = (dot00 * dot12 - dot01 * dot02) * denom;

    return (u >= 0) and (v >= 0) and (u + v <= 1);
}

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    fin >> n;
    int x, y;
    for (int i = 0; i < n; ++i) {
        fin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    memset(out, 0, sizeof(out));

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int count = 0;
                for (int l = 0; l < n; ++l) {
                    if (l == i or l == j or l == k) {
                        continue;
                    }

                    if (within(points[i], points[j], points[k], points[l])) {
                        ++count;
                    }
                }

                out[count]++;
            }
        }
    }

    for (int i = 0; i < n - 2; ++i) {
        fout << out[i] << '\n';
    }
    fout.close();

    return 0;
}
