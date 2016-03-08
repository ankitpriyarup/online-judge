//Problem        : Green Lights RoadTrip
//Language       : C++11
//Compiled Using : g++
//Version        : GCC 4.9.1
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

#include <iostream>
#include <string>
#include <algorithm>
#include <climits> 
#include <vector>
#include <utility>

typedef long long ll;
using namespace std;

vector<pair<ll, ll> > path;
vector<pair<ll, ll> > roads;

int N, R;

bool cross(ll a, ll b, ll c, ll d) {
    return a * d - b * c >= 0LL;
}

bool intersections(pair<ll, ll> s1, pair<ll,ll> e1, pair<ll, ll> s2, pair<ll, ll> e2) {
    ll bax = e1.first - s1.first;
    ll bay = e1.second - s1.second;

    ll cax = s2.first - s1.first;
    ll cay = s2.second - s1.second;

    ll dax = e2.first - s1.first;
    ll day = e2.second - s1.second;

    if (cross(bax, bay, cax, cay) == cross(bax, bay, dax, day)) {
        return false;
    }

    ll dcx = e2.first - s2.first;
    ll dcy = e2.second - s2.second;

    ll acx = s1.first - s2.first;
    ll acy = s1.second - s2.second;

    ll bcx = e1.first - s2.first;
    ll bcy = e1.second - s2.second;

    if (cross(dcx, dcy, acx, acy) == cross(dcx, dcy, bcx, bcy)) {
        return false;
    }

    return true;
}

int main() {
    int x, y, m, b, s, f;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x;
        if (cin.peek() == ',') cin.ignore();
        cin >> y;
        path.push_back(make_pair(x, y));
    }

    cin >> R;
    for (int i = 0; i < R; ++i) {
        cin >> m;
        if (cin.peek() == ',') cin.ignore();
        cin >> b;
        if (cin.peek() == ',') cin.ignore();
        cin >> s;
        if (cin.peek() == ',') cin.ignore();
        cin >> f;
        int y1 = 1LL * s * m + b;
        int y2 = 1LL * f * m + b;

        /*
        cout << '\n';
        cout << s << ' ' <<y1 << '\n';
        cout << f << ' ' <<y2 << '\n';
        */
        roads.push_back(make_pair(s, y1));
        roads.push_back(make_pair(f, y2));
    }

    long long ans = 0;
    for (int i = 1; i < N; ++i) {
        pair<int, int> start = path[i - 1];
        pair<int, int> end = path[i];
        if (start.first > end.first) {
            pair<int, int> t = start;
            start = end;
            end = t;
        }

        for (int j = 0; j < R; ++j) {
            pair<int, int> road_start = roads[2 * j];
            pair<int, int> road_end = roads[2 * j + 1];

            if (intersections(start, end, road_start, road_end)) {
                ans += 1;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
