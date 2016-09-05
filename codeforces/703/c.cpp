#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <complex>

using namespace std;

typedef complex<long double> pt;

int n;
long double w, v, u;
vector<pt> bus;

int main() {
  cin >> n >> w >> v >> u;

  // our line is y = (u / v) * (x - v * t)
  // v y = ux - u v t
  // u v t = ux - vy
  // t = x / v - y / u
  int x, y;
  long double t;

  long double mint = 1e18;
  long double maxt = 0.0;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    t = x / v - y / u;

    mint = min(mint, t);
    maxt = max(maxt, t);
  }

  cout << fixed << setprecision(10);
  if (mint > -1e-6) {
    cout << (w / u) << '\n';
  } else {
    cout << ((w / u) + maxt) << '\n';
  }

  return 0;
}
