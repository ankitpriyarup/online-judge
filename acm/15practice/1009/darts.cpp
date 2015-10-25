#include <iostream>

using namespace std;

int main() {
    int T, N;
    cin >> T;
    int x, y;

    while (T-- > 0) {
        cin >> N;
        int points = 0;

        while (N-- > 0) {
            cin >> x >> y;
            // radius is sqrt(x^2 + y^2)
            int rad = x * x + y * y;

            for (int p = 10; p > 0; --p) {
                int circrad = 20 * (11 - p) * 20 * (11 - p);
                if (rad <= circrad) {
                    points += p;
                    break;
                }
            }
        }
        cout << points << '\n';
    }

    return 0;
}
