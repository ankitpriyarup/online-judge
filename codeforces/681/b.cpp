#include <iostream>

using namespace std;

int main() {
  long long n;
  cin >> n;
  bool works = false;
  long long MAX = 1000000000;
  long long acap = (MAX / 1234567L) + 10;
  long long bcap = (MAX / 123456L) + 10;
  for (int a = 0; !works and a < acap; ++a) {
    for (int b = 0; !works and b < bcap; ++b) {
      long long rest = n - (a * 1234567L) - (b * 123456L);
      if (rest >= 0 and rest % 1234L == 0) {
        works = true;
        break;
      }
    }
  }

  cout << (works ? "YES" : "NO") << '\n';
  return 0;
}
