#include <iostream>

using namespace std;

int w, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> w >> m;

    // c0 + c1 w + c2 w^2 + ... = m
    // c0 + w (c1 + c2 w + ...) = m

    bool works = true;

    for (int i = 0; m > 0 && i <= 100; i++) {
        if ((m + 1) % w == 0) {
            m++;
        } else if ((m - 1) % w == 0) {
            m--;
        }
        if (m % w != 0) { 
          works = false;
          break;
        }
        m /= w;
    }

    if (works) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
