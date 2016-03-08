#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;

int main() {
    cin >> N >> M;

    // 2, 4, 8, 10, ... if n is odd, 6 * (n + 1)/2 - 4, else 6 * (n + 1)/2 - 2
    // 3, 9, 15, = 6*n + 3
    
    int index = (N + 1) / 2;
    int tallest2 = 6 * index - ((N % 2 == 0) ? 2 : 4);
    int tallest3 = 6 * M - 3;

    for (int m = 6; m < max(tallest2, tallest3); m += 6) {
        if (tallest3 > tallest2) {
            tallest3 -= 3;
            if (tallest3 > m and tallest3 % 6 == 0) {
                tallest3 -= 3;
            }
        } else {
            tallest2 -= 2;
            if (tallest2 > m and tallest2 % 6 == 0) {
                tallest2 -= 2;
            }
        }
    }

    cout << max(tallest2, tallest3) << '\n';
    return 0;
}
