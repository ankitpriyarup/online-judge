#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    double x, y;
    double sumx, sumy, arg;
    string cmd;

    while (cin >> n) {
        if (n == 0) {
            break;
        }

        string s;
        // clear the current line
        getline(cin, s);
        vector<pair<double, double> > vals;
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            istringstream iss(s);
            iss >> x >> y;
            double angle = 0;

            while (iss >> cmd >> arg) {
                if (cmd == "walk") {
                    x += arg * cos(angle * M_PI / 180.0);
                    y += arg * sin(angle * M_PI / 180.0);
                } else {
                    angle += arg;
                }
            }

            vals.push_back({x, y});
        }

        double sumx = 0;
        double sumy = 0;
        for (int i = 0; i < n; ++i) {
            sumx += vals[i].first;
            sumy += vals[i].second;
        }

        sumx /= n;
        sumy /= n;

        double max_error = 0;
        for (int i = 0; i < n; ++i) {
            double xd = vals[i].first - sumx;
            double yd = vals[i].second - sumy;

            max_error = max(max_error, sqrt(xd * xd + yd * yd));
        }

        cout << fixed << setprecision(12) << sumx << ' ' << sumy << ' ' << max_error << '\n';
    }

    return 0;
}
