#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    vector<int> sides(3, y);
    int moves = 0;
    while (sides[0] != x) {
        // change the smallest one
        // sides[0] + sides[1] == sides[2] + 1
        sides[0] = min(x, sides[1] + sides[2] - 1);
        sort(sides.begin(), sides.end());
        moves += 1;
    }

    printf("%d\n", moves);

    return 0;
}
