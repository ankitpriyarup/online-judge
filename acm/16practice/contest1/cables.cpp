#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#define PI 3.141592653589793238L
using namespace std;

typedef pair<pair<int, int>, double> edge;

long long D, L, C;
double R;
vector<pair<double, double> > cities;
vector<edge> edges;

bool operator<(const edge &e1, const edge &e2) {
    return e1.second < e2.second;
}

// find distance between cities a and b
double find_dist(int a, int b) {
    double circumference = PI * D;
}

int main() {
    int T;
    double x, y;
    cin >> T;
    while (T-- > 0) {
        cin >> D >> L >> C;
        R = D / 2.0L;
        for (int i = 0; i < C; ++i) {
            cin >> x >> y;
            cities.push_back(make_pair(x, y));
        }

        for (int i = 0; i < C; ++i) {
            for (int j = i + 1; j < C; ++j) {
                double dist = find_dist(i, j);
                edges.push_back(make_pair(make_pair(i, j), dist));
                cout << dist << '\n';
            }
        }

        sort(edges.begin(), edges.end());
        // prims

        // see if mst is less than L
    }
    return 0;
}
