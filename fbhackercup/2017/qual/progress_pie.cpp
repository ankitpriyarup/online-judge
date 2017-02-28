#include <iostream>
#include <cmath>

using namespace std;

int squared_dist(int x, int y) {
    return x * x + y * y;
}

int main() {
    const long double TWO_M_PI = 2.0L * M_PI;
    const long double THREE_HALF_M_PI = 3.0L * M_PI / 2.0L;

    int num_cases;
    cin >> num_cases;

    int p, x, y;
    for (int case_num = 1; case_num <= num_cases; ++case_num) {
        cin >> p >> x >> y;

        // Manipulate x and y so the angles make sense
        int used_x = x - 50;
        int used_y = y - 50;

        // rotate by 90 degrees clockwise
        used_x = 50 - y;
        used_y = x - 50; // used_x

        // mirror across x-axis
        used_x = -used_x;

        long double angle = atan2(used_y, used_x);

        if (angle < 0) {
            angle += TWO_M_PI;
        }

        if (angle >= TWO_M_PI) {
            angle -= TWO_M_PI;
        }

        long double p_angle = TWO_M_PI * p / 100.0L;

        // Special case is_center because atan2(0, 0) is undefined
        bool is_center = x == 50 and y == 50;

        bool in_circle = squared_dist(x - 50, y - 50) <= 50 * 50;
        bool is_black = is_center or (angle <= p_angle and in_circle);

        cout << "Case #" << case_num << ": " << (is_black ? "black" : "white") << '\n';
    }

    return 0;
}
