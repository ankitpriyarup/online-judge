#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

int n, m;
int a[100005];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a, a + n);
  cin >> m;

  int x;
  while (m-- > 0) {
    cin >> x;
    cout << (upper_bound(a, a + n, x) - a) << '\n';
  }
  return 0;
}
