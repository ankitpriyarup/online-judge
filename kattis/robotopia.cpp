#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-- > 0) {
        int l1, a1, l2, a2, lt, at;
        cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;
        int ax = -1;
        int ay = -1;
        for (int x = 1; x <= 10000; ++x) {
            int ll = lt - x * l1;
            int al = at - x * a1;
            if (ll % l2 == 0 and al % a2 == 0) {
                int y1 = ll / l2;
                int y2 = al / a2;

                if (y1 == y2 and y1 > 0) {
                    if (ax != -1) {
                        ax = -1;
                        break;
                    } else {
                        ax = x;
                        ay = y1;
                    }
                }
            }
        }

        if (ax == -1) {
            cout << "?\n";
        } else {
            cout << ax << ' ' << ay << '\n';
        }
    }
    return 0;
}
