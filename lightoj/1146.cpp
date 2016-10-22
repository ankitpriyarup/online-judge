#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int ax, ay, bx, by, cx, cy, dx, dy;

long double EPS = 1e-8;

long double calc(long double t) {
  long double xd = ax - cx + t * (bx - ax + cx - dx);
  long double yd = ay - cy + t * (by - ay + cy - dy);

  return sqrt(xd * xd + yd * yd);
}

int main() {
  int t;
  cin >> t;
  for (int case_num = 1; case_num <= t; ++case_num) {
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    long double lo = 0.0L;
    long double hi = 1.0L;

    while (hi - lo > EPS) {
      long double mid1 = lo + (hi - lo) / 3.0;
      long double mid2 = lo + 2.0 * (hi - lo) / 3.0;
      //cout << lo << ' ' << mid1 << ' ' << mid2 << ' ' << hi << '\n';
      if (calc(mid1) < calc(mid2)) {
        hi = mid2;
      } else {
        lo = mid1;
      }
    }

    cout << "Case " << case_num << ": " << fixed << setprecision(10) << calc(hi) << '\n';
  }
  return 0;
}
