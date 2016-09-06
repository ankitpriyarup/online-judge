#include <iostream>

using namespace std;

int A, B, n;

long long height(long long i) {
  return (i - 1) * B + A;
}
int main() {
  cin >> A >> B >> n;  

  int l;
  long long t, m;
  while (n-- > 0) {
    cin >> l >> t >> m;
    long long mt = m * t;
    long long hl = height(l);
    if (hl > t) {
      cout << -1 << '\n';
    } else {
      long long lo = l;
      long long hi = 1e10;
      while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        long long hr = height(mid);
        long long tower_sum = (mid - l + 1) * (hl + hr) / 2;
        if (t >= hr and mt >= tower_sum) {
          lo = mid;
        } else {
          hi = mid;
        }
      }

      cout << lo << '\n';
    }
  }
  return 0;
}
